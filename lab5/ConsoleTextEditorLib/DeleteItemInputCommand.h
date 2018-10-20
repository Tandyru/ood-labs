#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"

namespace input_command
{

struct DeleteItemInputCommand : public InputCommand
{
	Position position = END_POSITION;

	DeleteItemInputCommand(Position position);

	void Execute(IInputCommandExecutor& executor) override;

};

}