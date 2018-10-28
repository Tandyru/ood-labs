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

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace document;
using namespace input_command;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(IntegrationTests)
	{
	public:
		CDocument document;
		stringstream out;
		CInputCommandExecutor executor;

		IntegrationTests()
			: executor(document, out, [](ostream&) {})
		{
		}

		TEST_METHOD(TestSetTitle)
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

		TEST_METHOD(TestInsertParagraphAndImage)
		{
			const string firstParagraphText = "First paragraph text";
			const string firstParagraphNewText = "First paragraph new text";
			const string imageFilePath = R"(c:\image\file\path.png)";
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
			string expectedOutput = "Title: \n";
				expectedOutput += 
					"0. Paragraph: " + firstParagraphNewText + "\n" +
					"1. Image: " + to_string(imageWidth) + " " + to_string(imageHeight) + " " + imageFilePath + "\n";
			Assert::AreEqual(expectedOutput, out.str());
		}

	};
}