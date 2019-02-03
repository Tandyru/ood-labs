#pragma once
#include "Command.h"

namespace document
{
namespace command
{

class ICommandHistory
{
public:
	virtual void Do(std::unique_ptr<CCommand>&& command) = 0;

	virtual bool CanUndo() const = 0;
	virtual void Undo() = 0;

	virtual bool CanRedo() const = 0;
	virtual void Redo() = 0;

	virtual bool ShouldCreateCommand() const = 0;

	virtual ~ICommandHistory() = default;
};

}
}
