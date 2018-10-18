#include "stdafx.h"
#include "CppUnitTest.h"
#include "DocumentMock.h"
#include "../ConsoleTextEditorLib/InputCommandExecutor.h"
#include "../ConsoleTextEditorLib/InsertParagraphInputCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace command;
using namespace input_command;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(CommandExecutionTests)
	{
	public:
		stringstream out;
		CInputCommandExecutor executor;
		bool helpHandlerCalled = false;

		void HelpHandler(ostream& out)
		{
			helpHandlerCalled = true;
		}

		CommandExecutionTests()
			//: document(make_shared<CDocumentMock>())
			//, executor(document, out, bind(&CommandExecutionTests::HelpHandler, this, placeholders::_1))
		{
		}

		TEST_METHOD(TestHelpCommandExecution)
		{
			InputCommand command(InputCommandType::Help);

			command.Accept(executor);
			Assert::IsTrue(helpHandlerCalled);
		}

		TEST_METHOD(TestInsertParagraphCommandExecution)
		{
			command::Position expectedPosition = 3;
			const string expectedText = "Text";
			InsertParagraphInputCommand command(expectedPosition, expectedText);
			command.Accept(executor);
			//Assert::IsTrue(bool(document->lastCommandPosition));
			//Assert::AreEqual(expectedPosition, *document->lastCommandPosition);
		}

	};
}