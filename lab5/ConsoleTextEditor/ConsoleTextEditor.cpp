// ConsoleTextEditor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Document.h"
#include "InputCommandExecutor.h"
#include "HelpCommandExecutor.h"
#include "InputCommandsReader.h"

int main()
{
	std::cout << "Console Text Editor\n";
	document::CDocument document;
	input_command::CInputCommandExecutor executor(document, cout, [](ostream& out) {
		input_command::ShowCommandHelp(out);
	});
	ReadInputCommands(cin, cout, [&](auto inputCommand) {
		inputCommand->Execute(executor);
	}, [&](const auto& ex) {
		cout << "Error: " << ex.what() << endl;
	});
}

