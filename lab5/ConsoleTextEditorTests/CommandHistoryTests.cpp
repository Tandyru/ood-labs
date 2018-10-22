#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/CommandHistory.h"
#include "../ConsoleTextEditorLib/InsertParagraphCommand.h"
#include "DocumentMock.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace document::command;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(CommandHistoryTests)
	{
	public:
		CCommandHistory history;
		CDocumentMock document;

		TEST_METHOD(TestInitialState)
		{
			Assert::IsFalse(history.CanRedo());
			Assert::IsFalse(history.CanUndo());
		}

		TEST_METHOD(TestStateAfterOneCommandDo)
		{
			DoCommand();
			Assert::IsTrue(history.CanUndo());
			Assert::IsFalse(history.CanRedo());
		}

	private:
		void DoCommand()
		{
			history.Do(make_unique<CInsertParagraphCommand>(document, optional<size_t>(), "text"));
		}
	};
}