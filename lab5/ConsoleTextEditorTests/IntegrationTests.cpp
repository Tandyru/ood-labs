#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/Image.h"
#include "../ConsoleTextEditorLib/Paragraph.h"
#include "../ConsoleTextEditorLib/ConstDocumentItem.h"
#include "../ConsoleTextEditorLib/DocumentItem.h"
#include "../ConsoleTextEditorLib/Document.h"
#include "../ConsoleTextEditorLib/InvalidPositionException.h"
#include "../ConsoleTextEditorLib/InputCommandExecutor.h"
#include "../ConsoleTextEditorLib/InputCommandsReader.h"
#include "../ConsoleTextEditorLib/StringUtils.h"
#include "../ConsoleTextEditorLib/FileUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace document;
using namespace input_command;
using namespace filesystem;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(IntegrationTests)
	{
	public:
		CDocument document;
		stringstream out;
		CInputCommandExecutor executor;
		string imageFilePath = "../../ConsoleTextEditorTests/res/lamp.jpg";

		IntegrationTests()
			: executor(document, out, [](ostream&) {})
		{
		}

		TEST_METHOD(SetTitleCommandExecutionGetsCorrectOutput)
		{
			const string title = "Test document title";
			const string inputCommands = "SetTitle " + title;
			stringstream in(inputCommands);
			stringstream prompt;
			ReadInputCommands(in, prompt, [&](unique_ptr<input_command::InputCommand>&& inputCommand) {
				inputCommand->Execute(executor);
			}, [](auto) {});
			executor.ExecuteCommand(InputCommandType::List);
			const string expectedOutput = "Title: " + title + "\n";
			Assert::AreEqual(expectedOutput, out.str());
		}

		TEST_METHOD(ReplaceTextCommandReplacesTextOnUndoRedo)
		{
			const string firstParagraphText = "First paragraph text";
			const string firstParagraphNewText = "First paragraph new text";
			const string inputCommands =
				"InsertParagraph end " + firstParagraphText + "\n" +
				"ReplaceText 0 " + firstParagraphNewText + "\n" +
				"Undo\nUndo\n" +
				"Redo\nRedo\n";
			stringstream in(inputCommands);
			stringstream prompt;
			ReadInputCommands(in, prompt, [&](unique_ptr<input_command::InputCommand>&& inputCommand) {
				inputCommand->Execute(executor);
			}, [](auto) {});
			executor.ExecuteCommand(InputCommandType::List);
			string expectedOutput = "Title: \n";
			expectedOutput +=
				"0. Paragraph: " + firstParagraphNewText + "\n";
			Assert::AreEqual(expectedOutput, out.str());
		}

		TEST_METHOD(ParagraphAndImageCommandsExecutionProducesCorrectOutput)
		{
			const string firstParagraphText = "First paragraph text";
			const string firstParagraphNewText = "First paragraph new text";
			const int secondParagraphPosition = 1;
			const int imageWidth = 640;
			const int imageHeight = 480;
			const string inputCommands =
				"InsertParagraph end " + firstParagraphText + "\n" +
				"InsertImage end 320 240 " + imageFilePath + "\n" +
				"InsertParagraph " + to_string(secondParagraphPosition) + " To be deleted paragraph" + "\n" +
				"ResizeImage 2 " + to_string(imageWidth) + " " + to_string(imageHeight) + " " + "\n" +
				"DeleteItem " + std::to_string(secondParagraphPosition) + "\n" +
				"ReplaceText 0 " + firstParagraphNewText + "\n" +
				"Undo\nUndo\nUndo\nUndo\nUndo\nUndo\n" +
				"Redo\nRedo\nRedo\nRedo\nRedo\nRedo\n";
			stringstream in(inputCommands);
			stringstream prompt;
			ReadInputCommands(in, prompt, [&](unique_ptr<input_command::InputCommand>&& inputCommand) {
				inputCommand->Execute(executor);
			}, [](auto) {});
			executor.ExecuteCommand(InputCommandType::List);
			Assert::AreEqual(size_t(2), document.GetItemsCount());
			auto item = document.GetItem(1);
			auto image = item.GetImage();
			Assert::IsTrue(bool(image));
			auto imageSavePath = image->GetPath();
			string expectedOutput = "Title: \n";
				expectedOutput += 
					"0. Paragraph: " + firstParagraphNewText + "\n" +
					"1. Image: " + to_string(imageWidth) + " " + to_string(imageHeight) + " " + w2s(imageSavePath.native().c_str()) + "\n";
			Assert::AreEqual(expectedOutput, out.str());
		}

		TEST_METHOD(SaveCommandExecutionMakesOutputFileAndResourceCopies)
		{
			const string paragraphText = "First paragraph text";
			const string inputCommands =
				"InsertParagraph end " + paragraphText + "\n" +
				"InsertImage end 320 240 " + imageFilePath + "\n" + 
				"InsertImage end 640 480 " + imageFilePath + "\n";
			stringstream in(inputCommands);
			stringstream prompt;
			ReadInputCommands(in, prompt, [&](unique_ptr<input_command::InputCommand>&& inputCommand) {
				inputCommand->Execute(executor);
			}, [](auto) {});
			Path tempDirectoryPath = temp_directory_path() / GetUniqueFileName();
			create_directory(tempDirectoryPath);
			string htmlFileName = "output.html";
			Path htmlFilePath = tempDirectoryPath / htmlFileName;
			string htmlFilePathStr = w2s(htmlFilePath.native().c_str());
			SaveInputCommand saveCommand(htmlFilePathStr);
			executor.ExecuteCommand(saveCommand);
			Assert::IsTrue(exists(htmlFilePath));
			Assert::IsTrue(exists(tempDirectoryPath / "images" / "image1.jpg"));
			Assert::IsTrue(exists(tempDirectoryPath / "images" / "image2.jpg"));
			remove_all(tempDirectoryPath);
		}

	};
}