#pragma once
#include "InputCommand.h"
#include "Command.h"

namespace command
{

class IDocumentCommandFactory
{
public:
	virtual unique_ptr<CCommand> CreateDocumentCommand() const = 0;
};

}