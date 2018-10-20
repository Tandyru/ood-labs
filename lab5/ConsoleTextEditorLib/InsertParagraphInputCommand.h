#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"

namespace input_command
{

struct InsertParagraphInputCommand : public InputCommand
{
	Position position = END_POSITION;
	string text;

	InsertParagraphInputCommand(Position position, string text);

	void Execute(IInputCommandExecutor& executor) override;

};

}