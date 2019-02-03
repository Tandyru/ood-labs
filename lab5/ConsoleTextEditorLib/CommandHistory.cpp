#include "stdafx.h"
#include "CommandHistory.h"
#include "CompositeCommand.h"

using namespace std;

namespace document
{
namespace command
{

namespace
{
const auto MAX_HISTORY_SIZE = 10;
}

CCommandHistory::CCommandHistory()
{
}

void CCommandHistory::Do(unique_ptr<CCommand>&& command)
{
	EraseOldRedoCommands();
	m_history.push_back(move(command));
	try
	{
		DoCommand(**m_history.rbegin());
		RemoveOldCommands();
		m_currentPosition = m_history.size();
	}
	catch (std::exception& ex)
	{
		m_history.pop_back();
		throw ex;
	}
}

bool CCommandHistory::ShouldCreateCommand() const
{
	return !m_commandExecuting;
}

bool CCommandHistory::CanUndo() const
{
	return m_currentPosition > 0;
}

void CCommandHistory::Undo()
{
	if (CanUndo())
	{
		auto it = m_history.begin() + m_currentPosition - 1;
		auto& command = **it;
		UndoCommand(command);
		m_currentPosition--;
	}
}

bool CCommandHistory::CanRedo() const
{
	return m_currentPosition < m_history.size();
}

void CCommandHistory::Redo()
{
	if (CanRedo())
	{
		auto it = m_history.begin() + m_currentPosition;
		auto& command = **it;
		DoCommand(command);
		m_currentPosition++;
	}
}

void CCommandHistory::EraseOldRedoCommands()
{
	assert(m_currentPosition <= m_history.size());
	if (m_history.size() > m_currentPosition)
	{
		m_history.erase(m_history.begin() + m_currentPosition, m_history.end());
	}
}

namespace 
{

class CommandExecutionFlagSetter
{
public:
	CommandExecutionFlagSetter(bool & commandExecuting)
		: m_commandExecuting(commandExecuting)
	{
		m_commandExecuting = true;
	}

	~CommandExecutionFlagSetter()
	{
		m_commandExecuting = false;
	}

private:
	bool & m_commandExecuting;
};

}

void CCommandHistory::DoCommand(CCommand & command)
{
	CommandExecutionFlagSetter flagSetter(m_commandExecuting);
	command.Execute();
}

void CCommandHistory::UndoCommand(CCommand & command)
{
	CommandExecutionFlagSetter flagSetter(m_commandExecuting);
	command.Unexecute();
}

void CCommandHistory::RemoveOldCommands()
{
	if (m_history.size() > MAX_HISTORY_SIZE)
	{
		m_history.erase(m_history.begin(), m_history.begin() + (m_history.size() - MAX_HISTORY_SIZE));
	}
}

}
}
