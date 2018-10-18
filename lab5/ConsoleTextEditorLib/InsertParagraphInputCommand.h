#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"

namespace input_command
{

struct InsertParagraphInputCommand : public InputCommand
{
	command::Position position = command::END_POSITION;
	string text;

	InsertParagraphInputCommand(command::Position position, string text);

	void Execute(IInputCommandExecutor& executor) override;

};

}