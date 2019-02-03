#include "stdafx.h"
#include "InputCommandsReader.h"
#include "InputCommandParser.h"
#include <istream>
#include "ExitException.h"

using namespace std;
using namespace input_command;
using namespace command_parser;

void ReadInputCommands(istream & input, ostream & out, const InputCommandHandler& handler, const InputCommandErrorHandler& errorHandler)
{
	auto outputPrompt = [&out] {
		out << ">";
	};

	outputPrompt();
	string readline;
	while (getline(input, readline))
	{
		try
		{
			auto inputCommand = ParseInputCommand(readline);
			handler(move(inputCommand));
		}
		catch (const ExitException&)
		{
			break;
		}
		catch (const exception& ex)
		{
			errorHandler(ex);
		}
		outputPrompt();
	}
}
