#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"

namespace input_command
{
	struct DeleteItemInputCommand : public InputCommand
	{
		command::Position position = command::END_POSITION;
	};
}