#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleTextEditorLib/CommandHistory.h"
#include "../ConsoleTextEditorLib/InsertParagraphCommand.h"
#include "DocumentImplMock.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace document::command;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(CommandHistoryTests)
	{
	public:
		CCommandHistory history;
		CDocumentImplMock document;

		TEST_METHOD(InInitialStateHistoryCannotUndoAndRedo)
		{
			Assert::IsFalse(history.CanRedo());
			Assert::IsFalse(history.CanUndo());
		}

		TEST_METHOD(AfterOneCommandDoHistoryCanUndo)
		{
			DoCommand();
			Assert::IsTrue(history.CanUndo());
			Assert::IsFalse(history.CanRedo());
		}

		TEST_METHOD(AfterOneCommandDoUndoRedoHistoryCanUndoAndCannotRedo)
		{
			DoCommand();
			Assert::IsTrue(history.CanUndo());
			Assert::IsFalse(history.CanRedo());
			history.Undo();
			Assert::IsTrue(history.CanRedo());
			Assert::IsFalse(history.CanUndo());
			history.Redo();
			Assert::IsFalse(history.CanRedo());
			Assert::IsTrue(history.CanUndo());
		}

		TEST_METHOD(AfterTwoCommandsDoUndoRedoHistoryCanUndoAndCannotRedo)
		{
			DoCommand();
			DoCommand();
			Assert::IsTrue(history.CanUndo());
			history.Undo();
			Assert::IsTrue(history.CanRedo());
			Assert::IsTrue(history.CanUndo());
			history.Undo();
			Assert::IsTrue(history.CanRedo());
			history.Redo();
			Assert::IsTrue(history.CanRedo());
			Assert::IsTrue(history.CanUndo());
			history.Redo();
			Assert::IsFalse(history.CanRedo());
			Assert::IsTrue(history.CanUndo());
		}

		TEST_METHOD(AfterDoCommandAfterRedoHistoryCanUndoAndCannotRedo)
		{
			DoCommand();
			DoCommand();
			DoCommand();
			history.Redo();
			history.Redo();
			DoCommand();
			Assert::IsFalse(history.CanRedo());
			Assert::IsTrue(history.CanUndo());
		}

		TEST_METHOD(HistoryCanContainTenCommandsMaximum)
		{
			const auto MAX_HISTORY_SIZE = 10;
			for (auto counter = 0; counter < MAX_HISTORY_SIZE + 2; counter++)
			{
				DoCommand();
			}
			for (auto counter = 0; counter < MAX_HISTORY_SIZE; counter++)
			{
				history.Undo();
			}
			Assert::IsFalse(history.CanUndo());
			Assert::IsTrue(history.CanRedo());
		}

	private:
		void DoCommand()
		{
			std::shared_ptr<IParagraph> paragraph = std::make_shared<CParagraph>("text", nullptr);
			history.Do(std::make_unique<CInsertParagraphCommand>(document, std::optional<size_t>(), paragraph));
		}
	};
}