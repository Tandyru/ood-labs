#include "stdafx.h"
#include "InputCommandParser.h"
#include <regex>
#include "MapEnum.h"

using namespace command;

namespace command_parser
{

	unique_ptr<input_command::InputCommand> ParseInputCommand(string_view input)
	{
		static pair<const char*, CommandType> cmdNameMap[] =
		{
			{ "InsertParagraph", CommandType::InsertParagraph },
			{ "InsertImage", CommandType::InsertImage },
			{ "SetTitle", CommandType::SetTitle },
			{ "List", CommandType::List },
			{ "ReplaceText", CommandType::ReplaceText },
			{ "ResizeImage", CommandType::ResizeImage },
			{ "DeleteItem", CommandType::DeleteItem },
			{ "Help", CommandType::Help },
			{ "Undo", CommandType::Undo },
			{ "Redo", CommandType::Redo },
			{ "Save", CommandType::Save },
		};

		std::regex re(R"e(^(\w+))e");
		std::cmatch match;
		string str(input);
		if (std::regex_search(str.c_str() , match, re) && match.size() > 1) {
			const string name = match[1];
			auto type = StringMapEnum(cmdNameMap, name);
			// TODO: 
			return make_unique<input_command::InputCommand>(input_command::InputCommand{ type });
		}
		throw std::exception("Invalid command string format");
	}

}
