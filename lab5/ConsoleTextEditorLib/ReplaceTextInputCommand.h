#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"
#include <string>

namespace input_command
{

struct ReplaceTextInputCommand : public InputCommand
{
	command::Position position = command::END_POSITION;
	string text;

	ReplaceTextInputCommand(command::Position position, const string & text);

	void Execute(IInputCommandExecutor& executor) override;

};

}