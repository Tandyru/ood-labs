#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/InputCommandParser.h"
#include "../ConsoleTextEditorLib/InputCommands.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace input_command;
using namespace command_parser;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(CommandParserTests)
	{
	public:

		TEST_METHOD(TestParseType)
		{
			auto command = ParseInputCommand("InsertParagraph end The text \nof the paragraph.");
			Assert::IsTrue(command->type == InputCommandType::InsertParagraph);
		}

		TEST_METHOD(TestParseUnknownTypeThrowsException)
		{
			try
			{
				ParseInputCommand("UnknownType params");
				Assert::Fail();
			}
			catch (std::exception)
			{
			}
		}

		TEST_METHOD(TestParseInsertParagraph)
		{
			const string expectedParagraphText = "The text \nof the paragraph.";
			auto inputCommand = ParseInputCommand("InsertParagraph end "s + expectedParagraphText);
			auto& command = static_cast<InsertParagraphInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::InsertParagraph);
			Assert::IsTrue(command.position == END_POSITION);
			Assert::IsTrue(command.text == expectedParagraphText);
			const Position expectedPosition = 12;
			auto inputCommand2 = ParseInputCommand("InsertParagraph "s + to_string(*expectedPosition) + " " + expectedParagraphText);
			auto& command2 = static_cast<InsertParagraphInputCommand&>(*inputCommand2);
			Assert::IsTrue(command2.position == expectedPosition);
		}

		TEST_METHOD(TestParseInsertParagraphWithInvalidPosition)
		{
			try
			{
				ParseInputCommand("InsertParagraph invalid_position The text \nof the paragraph.");
				Assert::Fail();
			}
			catch (std::exception)
			{
			}
		}

		TEST_METHOD(TestParseInsertImage)
		{
			const unsigned int expectedPosition = 11;
			const unsigned int expectedWidth = 200;
			const unsigned int expectedHeight = 150;
			const string expectedPath = "c:\\image\\file\\path";
			auto inputCommand = ParseInputCommand("InsertImage"s + 
				" " + to_string(expectedPosition) + 
				" " + to_string(expectedWidth) +
				" " + to_string(expectedHeight) +
				" " + expectedPath
			);
			auto& command = static_cast<InsertImageInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::InsertImage);
			Assert::IsTrue(command.position == expectedPosition);
		}

		TEST_METHOD(TestParseSetTitle)
		{
			const string expectedTitle = "The Title";
			auto inputCommand = ParseInputCommand("SetTitle "s + expectedTitle);
			auto& command = static_cast<SetTitleInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::SetTitle);
			Assert::IsTrue(command.title == expectedTitle);

			inputCommand = ParseInputCommand("SetTitle");
			auto& command2 = static_cast<SetTitleInputCommand&>(*inputCommand);
			Assert::IsTrue(command2.title.empty());
		}

		TEST_METHOD(TestParseNonargCommands)
		{
			auto inputCommand = ParseInputCommand("List");
			Assert::IsTrue(inputCommand->type == InputCommandType::List);
			inputCommand = ParseInputCommand("Help");
			Assert::IsTrue(inputCommand->type == InputCommandType::Help);
			inputCommand = ParseInputCommand("Undo");
			Assert::IsTrue(inputCommand->type == InputCommandType::Undo);
			inputCommand = ParseInputCommand("Redo");
			Assert::IsTrue(inputCommand->type == InputCommandType::Redo);
		}

		TEST_METHOD(TestParseReplaceText)
		{
			const string expectedText = "The text \nof the paragraph to replace.";
			const unsigned int expectedPosition = 33;
			auto inputCommand = ParseInputCommand("ReplaceText "s + to_string(expectedPosition) + " " + expectedText);
			auto& command = static_cast<ReplaceTextInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::ReplaceText);
			Assert::IsTrue(command.position == expectedPosition);
			Assert::IsTrue(command.text == expectedText);
		}

		TEST_METHOD(TestParseResizeImage)
		{
			const unsigned int expectedPosition = 12;
			const unsigned int expectedWidth = 250;
			const unsigned int expectedHeight = 350;
			auto inputCommand = ParseInputCommand("ResizeImage"s +
				" " + to_string(expectedPosition) +
				" " + to_string(expectedWidth) +
				" " + to_string(expectedHeight)
			);
			auto& command = static_cast<ResizeImageInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::ResizeImage);
			Assert::IsTrue(command.position == expectedPosition);
			Assert::IsTrue(command.width == expectedWidth);
			Assert::IsTrue(command.height == expectedHeight);
		}

		TEST_METHOD(TestParseDeleteItem)
		{
			const unsigned int expectedPosition = 15;
			auto inputCommand = ParseInputCommand("DeleteItem"s +
				" " + to_string(expectedPosition)
			);
			Assert::IsTrue(inputCommand->type == InputCommandType::DeleteItem);
			auto& command = static_cast<DeleteItemInputCommand&>(*inputCommand);
			Assert::IsTrue(command.position == expectedPosition);
		}

		TEST_METHOD(TestParseSave)
		{
			const unsigned int expectedPosition = 15;
			const string expectedPath = "c:\\output\\file\\path";
			auto inputCommand = ParseInputCommand("Save"s +
				" " + expectedPath
			);
			Assert::IsTrue(inputCommand->type == InputCommandType::Save);
			auto& command = static_cast<SaveInputCommand&>(*inputCommand);
			Assert::IsTrue(command.path == expectedPath);
		}
	};
}