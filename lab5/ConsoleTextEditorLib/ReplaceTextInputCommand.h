#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"
#include <string>

namespace input_command
{

struct ReplaceTextInputCommand : public InputCommand
{
	Position position = END_POSITION;
	string text;

	ReplaceTextInputCommand(Position position, const string & text);

	void Execute(IInputCommandExecutor& executor) override;

};

}