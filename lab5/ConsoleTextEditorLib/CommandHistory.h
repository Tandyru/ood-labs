#pragma once
#include "Command.h"

namespace document
{
namespace command
{

class CCommandHistory
{
public:
	CCommandHistory() = default;

	CCommandHistory(const CCommandHistory&) = delete;

	void Do(unique_ptr<CCommand>&& command);

	bool CanUndo() const;
	void Undo();

	bool CanRedo() const;
	void Redo();

private:
	vector<unique_ptr<CCommand>> m_history;
	size_t m_currentPosition = 0;
};

}
}
