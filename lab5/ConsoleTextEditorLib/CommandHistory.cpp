#include "stdafx.h"
#include "CommandHistory.h"

namespace document
{
namespace command
{

void CCommandHistory::Do(unique_ptr<CCommand>&& command)
{
	// TODO: 
	// erase after current commands
	// push back command into the history
	// try do the command
	// on exception remove command from history and rethrow
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

}
}
