#pragma once
#include "InputCommand.h"
#include <string>

namespace input_command
{

struct SetTitleInputCommand : public InputCommand
{
	std::string title;

	SetTitleInputCommand(const std::string& title);

	void Execute(IInputCommandExecutor& executor) override;

};

}