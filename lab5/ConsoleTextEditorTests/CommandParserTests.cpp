#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/InputCommandParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(CommandParserTests)
	{
	public:

		TEST_METHOD(TestParseType)
		{
			auto command = command_parser::ParseInputCommand("InsertParagraph end The text \nof the paragraph.");
			Assert::IsTrue(command->type == command::CommandType::InsertParagraph);
		}

		TEST_METHOD(TestParseSetTitle)
		{
			// TODO: Your test code here
		}

	};
}