#include "stdafx.h"
#include "CommandHistory.h"
#include "CommandCombiner.h"

namespace document
{
namespace command
{

namespace
{
const auto MAX_HISTORY_SIZE = 10;
}

void CCommandHistory::Do(unique_ptr<CCommand>&& command)
{
	EraseOldRedoCommands();
	CCommand* cmd = &(*command);
	if (!TryCombineWithPrev(*cmd))
	{
		m_history.push_back(move(command));
		unique_ptr<CCommand>& cmdPtr = *m_history.rbegin();
		cmd = &*(cmdPtr);
	}
	try
	{
		DoCommand(*cmd);
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
		command.Execute();
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
		command.Execute();
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

void CCommandHistory::DoCommand(CCommand & command)
{
	command.Execute();
}

void CCommandHistory::RemoveOldCommands()
{
	if (m_history.size() > MAX_HISTORY_SIZE)
	{
		m_history.erase(m_history.begin(), m_history.begin() + (m_history.size() - MAX_HISTORY_SIZE));
	}
}

bool CCommandHistory::TryCombineWithPrev(CCommand & command)
{
	if (m_history.size() > 0 && m_currentPosition == m_history.size())
	{
		auto preCommandIt = m_history.rbegin();
		auto& prevCommand = **preCommandIt;
		CCommandCombiner combiner;
		auto combined = combiner.Combine(prevCommand, command);
		if (combined)
		{
			m_history.pop_back();
			m_history.push_back(move(combined));
		}
	}
	return false;
}

}
}
