#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/InputCommandParser.h"
#include "../ConsoleTextEditorLib/InsertParagraphInputCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace command;
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
			Assert::IsTrue(command->type == CommandType::InsertParagraph);
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
			Assert::IsTrue(command.type == CommandType::InsertParagraph);
			Assert::IsTrue(command.position == END_POSITION);
			Assert::IsTrue(command.text == expectedParagraphText);
			const Position expectedPosition = 12;
			auto inputCommand2 = ParseInputCommand("InsertParagraph "s + to_string(expectedPosition) + " " + expectedParagraphText);
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

		TEST_METHOD(TestParseSetTitle)
		{
			// TODO: Your test code here
		}

	};
}