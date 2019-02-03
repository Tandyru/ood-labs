#pragma once
#include "Command.h"
#include "ICommandHistory.h"

namespace document
{
namespace command
{

class CCommandHistory : public ICommandHistory
{
public:
	CCommandHistory();

	CCommandHistory(const CCommandHistory&) = delete;

	void Do(std::unique_ptr<CCommand>&& command) override;

	bool ShouldCreateCommand() const override;

	bool CanUndo() const override;
	void Undo() override;

	bool CanRedo() const override;
	void Redo() override;

private:
	void EraseOldRedoCommands();
	void DoCommand(CCommand& command);
	void UndoCommand(CCommand& command);
	void RemoveOldCommands();

private:
	std::vector<std::unique_ptr<CCommand>> m_history;
	size_t m_currentPosition = 0;
	bool m_commandExecuting = false;
};

}
}
