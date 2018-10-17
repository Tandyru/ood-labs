#include "stdafx.h"
#include "CppUnitTest.h"
#include "DocumentMock.h"
#include "../ConsoleTextEditorLib/InputCommandExecutor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace command;
using namespace input_command;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(CommandExecutionTests)
	{
	public:
		shared_ptr<CDocumentMock> document;
		stringstream out;
		CInputCommandExecutor executor;

		void HelpHandler(ostream& out)
		{
		}

		CommandExecutionTests()
			: document(make_shared<CDocumentMock>())
			, executor(document, out, [](ostream&) {}) // bind(&CommandExecutionTests::HelpHandler, this)
		{
		}

		TEST_METHOD(TestHelpCommandExecution)
		{
			InputCommand command{ InputCommandType::Help };

			//Assert::IsTrue(command->type == InputCommandType::InsertParagraph);
		}

	};
}