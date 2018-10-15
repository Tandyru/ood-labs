#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/Image.h"
#include "../ConsoleTextEditorLib/Paragraph.h"
#include "../ConsoleTextEditorLib/ConstDocumentItem.h"
#include "../ConsoleTextEditorLib/DocumentItem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace document;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(DocumentTests)
	{
	public:

		TEST_METHOD(TestImageConstruction)
		{
			Path expectedPath = "image/file/path";
			int expectedWidth = 300;
			int expectedHeight = 200;

			CImage image(expectedPath, expectedWidth, expectedHeight);

			Assert::IsTrue(expectedPath == image.GetPath());
			Assert::AreEqual(expectedWidth, image.GetWidth());
			Assert::AreEqual(expectedHeight, image.GetHeight());
		}

		TEST_METHOD(TestImageResize)
		{
			CImage image("image/file/path", 300, 200);

			int expectedWidth = 400;
			int expectedHeight = 350;

			image.Resize(expectedWidth, expectedHeight);

			Assert::AreEqual(expectedWidth, image.GetWidth());
			Assert::AreEqual(expectedHeight, image.GetHeight());
		}

		TEST_METHOD(TestParagraphConstruction)
		{
			auto expectedText = "paragraph text"s;

			CParagraph paragraph(expectedText);

			Assert::AreEqual(expectedText, paragraph.GetText());
		}

		TEST_METHOD(TestParagraphSetText)
		{
			auto expectedText = "paragraph text"s;

			CParagraph paragraph("initial text");

			paragraph.SetText(expectedText);

			Assert::AreEqual(expectedText, paragraph.GetText());
		}

		TEST_METHOD(TestConstDocumentItemContructionWithImage)
		{
			auto image = make_shared<CImage>("image/file/path", 300, 200);

			CConstDocumentItem item(image);

			Assert::IsTrue(bool(item.GetImage()));
			Assert::IsTrue(!bool(item.GetParagraph()));
		}

		TEST_METHOD(TestConstDocumentItemContructionWithParagraph)
		{
			auto paragraph = make_shared<CParagraph>("initial text");

			CConstDocumentItem item(paragraph);

			Assert::IsTrue(!bool(item.GetImage()));
			Assert::IsTrue(bool(item.GetParagraph()));
		}

		TEST_METHOD(TestDocumentItemContructionWithImage)
		{
			auto image = make_shared<CImage>("image/file/path", 300, 200);

			CDocumentItem item(image);

			Assert::IsTrue(bool(item.GetImage()));
			Assert::IsTrue(!bool(item.GetParagraph()));
		}

		TEST_METHOD(TestDocumentItemContructionWithParagraph)
		{
			auto paragraph = make_shared<CParagraph>("initial text");

			CDocumentItem item(paragraph);

			Assert::IsTrue(!bool(item.GetImage()));
			Assert::IsTrue(bool(item.GetParagraph()));
		}
	};
}