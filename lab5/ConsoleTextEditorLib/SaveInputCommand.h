#pragma once
#include "InputCommand.h"
#include <string>

namespace input_command
{

struct SaveInputCommand : public InputCommand
{
	string path;

	SaveInputCommand(const string& path);

	void Execute(IInputCommandExecutor& executor) override;
};

}