#include "stdafx.h"
#include "CommandHistory.h"

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
	// TODO: 
	// erase after current commands
	EraseOldRedoCommands();
	// push back command into the history
	m_history.push_back(move(command));
	try
	{
		// try do the command
		DoCommand(*(*m_history.rend()));
		// remove first command if command count > 10
		RemoveOldCommands();
	}
	catch (std::exception& e)
	{
		// on exception remove command from history and rethrow

	}
}

bool CCommandHistory::CanUndo() const
{
	return m_currentPosition > 0; // ?
}

void CCommandHistory::Undo()
{
	// TODO:
}

bool CCommandHistory::CanRedo() const
{
	return m_currentPosition < m_history.size(); // ?
}

void CCommandHistory::Redo()
{
	// TODO:
}

void CCommandHistory::EraseOldRedoCommands()
{
	assert(m_currentPosition <= m_history.size());
	if (m_history.size() > m_currentPosition)
	{
		m_history.erase(m_history.begin() + m_currentPosition, m_history.end());
	}
}

void CCommandHistory::DoCommand(const CCommand & command)
{
	// ??
}

void CCommandHistory::RemoveOldCommands()
{
	if (m_history.size() > MAX_HISTORY_SIZE)
	{

	}
	// ??
}

}
}
