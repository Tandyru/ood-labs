#pragma once
#include "InputCommandType.h"

namespace input_command
{

class IInputCommandVisitor;

struct InputCommand
{
	InputCommandType type;

	InputCommand(InputCommandType type);

	virtual void Accept(IInputCommandVisitor& visitor);
	virtual ~InputCommand() = default;
};

}