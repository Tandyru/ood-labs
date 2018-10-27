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
			string title = "Test document title";
			string inputCommands = "SetTitle " + title;
			stringstream in(inputCommands);
			ReadInputCommands(in, [&](unique_ptr<input_command::InputCommand>&& inputCommand) {
				inputCommand->Execute(executor);
			});
			executor.ExecuteCommand(InputCommandType::List);
			string expectedOutput = "Title: " + title;
			Assert::AreEqual(expectedOutput, out.str());
		}

	};
}