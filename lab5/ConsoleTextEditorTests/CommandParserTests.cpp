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

		TEST_METHOD(ParsingOfInsertParagraphInputCommandShouldCreateCommandOfAppropriateType)
		{
			auto command = ParseInputCommand("InsertParagraph end The text \nof the paragraph.");
			Assert::IsTrue(command->type == InputCommandType::InsertParagraph);
		}

		TEST_METHOD(ParsingOfUnknownCommandShouldThrowsException)
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

		TEST_METHOD(InsertParagraphParsedCommandContainsCorrectData)
		{
			const string expectedParagraphText = "The text \nof the paragraph.";
			auto inputCommand = ParseInputCommand("InsertParagraph end "s + expectedParagraphText);
			auto& command = dynamic_cast<InsertParagraphInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::InsertParagraph);
			Assert::IsTrue(command.position == END_POSITION);
			Assert::IsTrue(command.text == expectedParagraphText);
			const Position expectedPosition = 12;
			auto inputCommand2 = ParseInputCommand("InsertParagraph "s + to_string(*expectedPosition) + " " + expectedParagraphText);
			auto& command2 = dynamic_cast<InsertParagraphInputCommand&>(*inputCommand2);
			Assert::IsTrue(command2.position == expectedPosition);
		}

		TEST_METHOD(ParsingOfInsertParagraphCommandWithInvalidPositionThrowsException)
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

		TEST_METHOD(InsertImageParsedCommandContainsCorrectData)
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
			auto& command = dynamic_cast<InsertImageInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::InsertImage);
			Assert::IsTrue(command.position == expectedPosition);
		}

		TEST_METHOD(SetTitleParsedCommandContainsCorrectTitle)
		{
			const string expectedTitle = "The Title";
			auto inputCommand = ParseInputCommand("SetTitle "s + expectedTitle);
			auto& command = dynamic_cast<SetTitleInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::SetTitle);
			Assert::IsTrue(command.title == expectedTitle);
		}

		TEST_METHOD(SetTitleParsedCommandContainsEmptyTitleIfTitleArgumentAbsent)
		{
			auto inputCommand = ParseInputCommand("SetTitle");
			auto& command = dynamic_cast<SetTitleInputCommand&>(*inputCommand);
			Assert::IsTrue(command.title.empty());
		}

		TEST_METHOD(NonargParsedCommandsHaveCorrectType)
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

		TEST_METHOD(ReplaceTextParsedCommandContainsCorrectData)
		{
			const string expectedText = "The text \nof the paragraph to replace.";
			const unsigned int expectedPosition = 33;
			auto inputCommand = ParseInputCommand("ReplaceText "s + to_string(expectedPosition) + " " + expectedText);
			auto& command = dynamic_cast<ReplaceTextInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::ReplaceText);
			Assert::IsTrue(command.position == expectedPosition);
			Assert::IsTrue(command.text == expectedText);
		}

		TEST_METHOD(ResizeImageParsedCommandContainsCorrectData)
		{
			const unsigned int expectedPosition = 12;
			const unsigned int expectedWidth = 250;
			const unsigned int expectedHeight = 350;
			auto inputCommand = ParseInputCommand("ResizeImage"s +
				" " + to_string(expectedPosition) +
				" " + to_string(expectedWidth) +
				" " + to_string(expectedHeight)
			);
			auto& command = dynamic_cast<ResizeImageInputCommand&>(*inputCommand);
			Assert::IsTrue(command.type == InputCommandType::ResizeImage);
			Assert::IsTrue(command.position == expectedPosition);
			Assert::IsTrue(command.width == expectedWidth);
			Assert::IsTrue(command.height == expectedHeight);
		}

		TEST_METHOD(DeleteItemParsedCommandContainsCorrectTypeAndPosition)
		{
			const unsigned int expectedPosition = 15;
			auto inputCommand = ParseInputCommand("DeleteItem"s +
				" " + to_string(expectedPosition)
			);
			Assert::IsTrue(inputCommand->type == InputCommandType::DeleteItem);
			auto& command = dynamic_cast<DeleteItemInputCommand&>(*inputCommand);
			Assert::IsTrue(command.position == expectedPosition);
		}

		TEST_METHOD(SaveParsedCommandContainsCorrectTypeAndPath)
		{
			const unsigned int expectedPosition = 15;
			const string expectedPath = "c:\\output\\file\\path";
			auto inputCommand = ParseInputCommand("Save"s +
				" " + expectedPath
			);
			Assert::IsTrue(inputCommand->type == InputCommandType::Save);
			auto& command = dynamic_cast<SaveInputCommand&>(*inputCommand);
			Assert::IsTrue(command.path == expectedPath);
		}
	};
}