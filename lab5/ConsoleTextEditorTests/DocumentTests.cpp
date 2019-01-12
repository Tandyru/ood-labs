#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/Image.h"
#include "../ConsoleTextEditorLib/Paragraph.h"
#include "../ConsoleTextEditorLib/ConstDocumentItem.h"
#include "../ConsoleTextEditorLib/DocumentItem.h"
#include "../ConsoleTextEditorLib/Document.h"
#include "../ConsoleTextEditorLib/InvalidPositionException.h"
#include "ResourceMock.h"
#pragma warning(disable: 4834)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace document;
using namespace resources;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(DocumentTests)
	{
	public:
		CDocument document;
		shared_ptr<resources::IResource> resource;
		string imagePath = "../../ConsoleTextEditorTests/res/lamp.jpg";

		TEST_METHOD(TestImageConstruction)
		{
			int expectedWidth = 300;
			int expectedHeight = 200;

			CImage image(resource, expectedWidth, expectedHeight, nullptr, nullptr);

			Assert::AreEqual(expectedWidth, image.GetWidth());
			Assert::AreEqual(expectedHeight, image.GetHeight());
		}

		TEST_METHOD(TestImageResize)
		{
			CImage image(resource, 300, 200, nullptr, nullptr);

			int expectedWidth = 400;
			int expectedHeight = 350;

			image.Resize(expectedWidth, expectedHeight);

			Assert::AreEqual(expectedWidth, image.GetWidth());
			Assert::AreEqual(expectedHeight, image.GetHeight());
		}

		TEST_METHOD(TestParagraphConstruction)
		{
			auto expectedText = "paragraph text"s;

			CParagraph paragraph(expectedText, nullptr, nullptr);

			Assert::AreEqual(expectedText, paragraph.GetText());
		}

		TEST_METHOD(TestParagraphSetText)
		{
			auto expectedText = "paragraph text"s;

			CParagraph paragraph("initial text", nullptr, nullptr);

			paragraph.SetText(expectedText);

			Assert::AreEqual(expectedText, paragraph.GetText());
		}

		TEST_METHOD(TestConstDocumentItemContructionWithImage)
		{
			auto image = make_shared<CImage>(resource, 300, 200, nullptr, nullptr);

			CConstDocumentItem item(image);

			Assert::IsTrue(bool(item.GetImage()));
			Assert::IsTrue(!bool(item.GetParagraph()));
		}

		TEST_METHOD(TestConstDocumentItemContructionWithParagraph)
		{
			auto paragraph = make_shared<CParagraph>("initial text", nullptr, nullptr);

			CConstDocumentItem item(paragraph);

			Assert::IsTrue(!bool(item.GetImage()));
			Assert::IsTrue(bool(item.GetParagraph()));
		}

		TEST_METHOD(TestDocumentItemContructionWithImage)
		{
			auto image = make_shared<CImage>(resource, 300, 200, nullptr, nullptr);

			CDocumentItem item(image);

			Assert::IsTrue(bool(item.GetImage()));
			Assert::IsTrue(!bool(item.GetParagraph()));
		}

		TEST_METHOD(TestDocumentItemContructionWithParagraph)
		{
			auto paragraph = make_shared<CParagraph>("initial text", nullptr, nullptr);

			CDocumentItem item(paragraph);

			Assert::IsTrue(!bool(item.GetImage()));
			Assert::IsTrue(bool(item.GetParagraph()));
		}

		TEST_METHOD(TestInsertParagraphIntoInvalidPosition)
		{
			Assert::ExpectException<CInvalidPositionException>([&]() {
				document.InsertParagraph("", 1);
			});
		}

		TEST_METHOD(TestInsertParagraph)
		{
			const auto expectedText = "paragraphText";

			document.InsertParagraph(expectedText);

			Assert::IsTrue(document.GetItemsCount() == 1);
			const CConstDocumentItem item = document.GetItem(0);
			const auto paragraph = item.GetParagraph();
			Assert::IsTrue(bool(paragraph));
			Assert::IsFalse(bool(item.GetImage()));
			Assert::AreEqual(string(expectedText), paragraph->GetText());
		}

		TEST_METHOD(TestInsertParagraphIntoNonendPosition)
		{
			document.InsertParagraph("Second paragraph");
			const auto firstParagraphText = "First paragraph";
			document.InsertParagraph(firstParagraphText, 0);
			Assert::AreEqual(size_t(2), document.GetItemsCount());
			const CConstDocumentItem item = document.GetItem(0);
			const auto paragraph = item.GetParagraph();
			Assert::IsTrue(bool(paragraph));
			Assert::AreEqual(string(firstParagraphText), paragraph->GetText());
		}

		TEST_METHOD(TestInsertParagraphBeforeImage)
		{
			const auto firstParagraphText = "First paragraph";
			const auto secondParagraphText = "Second paragraph";
			document.InsertParagraph(firstParagraphText);
			document.InsertImage(imagePath, 300, 200);
			document.InsertParagraph("Second paragraph", 1);
			Assert::AreEqual(size_t(3), document.GetItemsCount());
			const CConstDocumentItem item = document.GetItem(1);
			const auto paragraph = item.GetParagraph();
			Assert::IsTrue(bool(paragraph));
			Assert::AreEqual(string(secondParagraphText), paragraph->GetText());
		}

		TEST_METHOD(TestInsertImage)
		{
			const auto expectedPath = imagePath;
			const auto expectedWidth = 300;
			const auto expectedHeight = 200;

			document.InsertImage(expectedPath, expectedWidth, expectedHeight);

			Assert::IsTrue(document.GetItemsCount() == 1);
			const CConstDocumentItem item = document.GetItem(0);
			const auto image = item.GetImage();
			Assert::IsTrue(bool(image));
			Assert::IsFalse(bool(item.GetParagraph()));
			Assert::AreNotEqual(string(expectedPath), image->GetPath().string());
			Assert::IsTrue(filesystem::exists(image->GetPath()));
			Assert::AreEqual(expectedWidth, image->GetWidth());
			Assert::AreEqual(expectedHeight, image->GetHeight());
		}

		TEST_METHOD(TestImageFileLifeCicle)
		{
			document.InsertImage(imagePath, 320, 240);
			Path tmpImagePath;
			{
				const CConstDocumentItem item = document.GetItem(0);
				const auto image = item.GetImage();
				Assert::IsTrue(bool(image));
				tmpImagePath = image->GetPath();
			}
			Assert::IsTrue(filesystem::exists(tmpImagePath));
			document.Undo();
			Assert::IsTrue(filesystem::exists(tmpImagePath));
			document.InsertParagraph("text");
			Assert::IsTrue(!filesystem::exists(tmpImagePath));
		}

		TEST_METHOD(TestGetItemInvalidIndex)
		{
			Assert::ExpectException<CInvalidPositionException>([&]() {
				document.GetItem(10);
			});
		}

		TEST_METHOD(TestDeleteItem)
		{
			document.InsertParagraph("");
			document.DeleteItem(0);
			Assert::AreEqual(size_t(0), document.GetItemsCount());
		}

		TEST_METHOD(TestReplaceText)
		{
			const string expectedOldText = "oldText";
			document.InsertParagraph("oldText");
			const string expectedText = "newText";
			auto item = document.GetItem(0);
			auto paragraph0 = item.GetParagraph();
			paragraph0->SetText(expectedText);
			Assert::AreEqual(size_t(1), document.GetItemsCount());
			const auto paragraph = document.GetItem(0).GetParagraph();
			Assert::AreEqual(string(expectedText), paragraph->GetText());
			Assert::IsTrue(document.CanUndo());
			document.Undo(); // undo "replace text" command
			Assert::IsTrue(document.CanUndo());
			const auto paragraph2 = document.GetItem(0).GetParagraph();
			Assert::AreEqual(string(expectedOldText), paragraph2->GetText());
			document.Undo(); // undo "insert paragraph" command
			Assert::IsFalse(document.CanUndo());
		}

		TEST_METHOD(TestResizeImage)
		{
			document.InsertImage(imagePath, 300, 200);
			auto item = document.GetItem(0);
			auto image = item.GetImage();
			image->Resize(600, 400);
			Assert::AreEqual(size_t(1), document.GetItemsCount());
			Assert::IsTrue(document.CanUndo());
			document.Undo(); // undo "resize image" command
			Assert::IsTrue(document.CanUndo());
			document.Undo(); // undo "insert image" command
			Assert::IsFalse(document.CanUndo());
		}

		TEST_METHOD(TestSetTitle)
		{
			const string expectedTitle = "Test Title";
			document.SetTitle(expectedTitle);
			Assert::AreEqual(expectedTitle, document.GetTitle());
			Assert::IsTrue(document.CanUndo());
			document.Undo();
			Assert::AreEqual(string(), document.GetTitle());
		}

		TEST_METHOD(TestImageResource)
		{
			document.InsertImage(imagePath, 300, 200);

		}
	};
}