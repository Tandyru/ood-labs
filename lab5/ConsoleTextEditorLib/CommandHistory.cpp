#include "stdafx.h"
#include "CommandHistory.h"
#include "CompositeCommand.h"

namespace document
{
namespace command
{

namespace
{
const auto MAX_HISTORY_SIZE = 10;
}

CCommandHistory::CCommandHistory(const CommandExecutionBegin& commandExecutionBegin, 
	const CommandExecutionEnd& commandExecutionEnd)
	: m_commandExecutionBegin(commandExecutionBegin)
	, m_commandExecutionEnd(commandExecutionEnd)
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
class BeginEndHandlerCaller
{
public:
	BeginEndHandlerCaller(const CCommandHistory::CommandExecutionBegin& commandExecutionBegin,
		const CCommandHistory::CommandExecutionEnd& commandExecutionEnd)
		: m_commandExecutionEnd(commandExecutionEnd)
	{
		if (commandExecutionBegin)
		{
			try
			{
				commandExecutionBegin();
			} 
			catch (...)
			{
			}
		}
	}
	~BeginEndHandlerCaller()
	{
		if (m_commandExecutionEnd)
		{
			try
			{
				m_commandExecutionEnd();
			}
			catch (...)
			{
			}
		}
	}
private:
	CCommandHistory::CommandExecutionEnd m_commandExecutionEnd;
};
}

void CCommandHistory::DoCommand(CCommand & command)
{
	BeginEndHandlerCaller beginEndCaller(m_commandExecutionBegin, m_commandExecutionEnd);
	command.Execute();
}

void CCommandHistory::UndoCommand(CCommand & command)
{
	BeginEndHandlerCaller beginEndCaller(m_commandExecutionBegin, m_commandExecutionEnd);
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
