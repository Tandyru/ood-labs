#pragma once
#include "InputCommand.h"
#include <string>

namespace input_command
{

struct SetTitleInputCommand : public InputCommand
{
	string title;

	SetTitleInputCommand(const string& title);

	void Accept(IInputCommandVisitor& executor) override;

};

}