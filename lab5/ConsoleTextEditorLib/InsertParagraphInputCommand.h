#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"

using namespace std;

namespace input_command
{

struct InsertParagraphInputCommand : public InputCommand
{
	Position position = END_POSITION;
	std::string text;

	InsertParagraphInputCommand(Position position, std::string text);

	void Execute(IInputCommandExecutor& executor) override;

};

}