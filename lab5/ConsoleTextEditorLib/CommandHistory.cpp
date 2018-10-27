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

CCommandHistory::CCommandHistory(const ShouldCombine & shouldCombine)
	: m_shouldCombine(shouldCombine)
{
}

void CCommandHistory::Do(unique_ptr<CCommand>&& command)
{
	EraseOldRedoCommands();
	if (ShoudCombineWithPrev(*command))
	{
		unique_ptr<CCommand>& lastCommand = *(m_history.rbegin());
		lastCommand->Unexecute();
		auto& document = lastCommand->GetDocument();
		CCompositeCommand::Commands commands;
		commands.push_back(move(lastCommand));
		commands.push_back(move(command));
		auto compositeCommand = make_unique<CCompositeCommand>(document, move(commands));
		m_history.pop_back();
		m_history.push_back(move(compositeCommand));
	}
	else
	{
		m_history.push_back(move(command));
	}
	CCommand& cmd = **m_history.rbegin();
	try
	{
		DoCommand(cmd);
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
		command.Unexecute();
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

bool CCommandHistory::ShoudCombineWithPrev(CCommand & command)
{
	if (m_shouldCombine && m_history.size() > 0 && m_currentPosition == m_history.size())
	{
		auto preCommandIt = m_history.rbegin();
		auto& prevCommand = **preCommandIt;
		return m_shouldCombine(prevCommand, command);
	}
	return false;
}

}
}
