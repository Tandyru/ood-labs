#include "stdafx.h"
#include "CppUnitTest.h"
#include "DocumentMock.h"
#include "DocumentImageItemMock.h"
#include "../ConsoleTextEditorLib/InputCommandExecutor.h"
#include "../ConsoleTextEditorLib/InsertParagraphInputCommand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace input_command;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(CommandExecutionTests)
	{
	public:
		stringstream out;
		CDocumentMock document;
		CInputCommandExecutor executor;
		bool helpHandlerCalled = false;

		void HelpHandler(ostream& out)
		{
			helpHandlerCalled = true;
		}

		CommandExecutionTests()
			: executor(document, out, bind(&CommandExecutionTests::HelpHandler, this, placeholders::_1))
		{
		}

		TEST_METHOD(TestHelpCommandExecution)
		{
			InputCommand command(InputCommandType::Help);

			command.Execute(executor);
			Assert::IsTrue(helpHandlerCalled);
		}

		TEST_METHOD(TestInsertParagraphCommandExecution)
		{
			Position expectedPosition = 3;
			const string expectedText = "Text";
			InsertParagraphInputCommand command(expectedPosition, expectedText);
			command.Execute(executor);
			Assert::IsTrue(bool(document.lastCommandPosition));
			Assert::IsTrue(expectedPosition == *(document.lastCommandPosition));
		}

		TEST_METHOD(TestResizeImageCommandExecution)
		{
			document.item = make_unique<DocumentImageItemMock>();

			const Position expectedPosition = 3;
			const unsigned int expectedWidth = 640;
			const unsigned int expectedHeight = 480;
			ResizeImageInputCommand command(expectedPosition, expectedWidth, expectedHeight);
			command.Execute(executor);
			Assert::AreEqual(int(expectedWidth), document.item->GetImage()->GetWidth());
			Assert::AreEqual(int(expectedHeight), document.item->GetImage()->GetHeight());
		}

	};
}