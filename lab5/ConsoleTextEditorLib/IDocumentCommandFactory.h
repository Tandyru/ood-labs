#pragma once
#include "InputCommand.h"
#include "Command.h"

namespace document
{

class IDocumentCommandFactory
{
public:
	virtual unique_ptr<command::CCommand> CreateDocumentCommand() const = 0;
};

}