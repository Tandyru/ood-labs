#include "stdafx.h"
#include "InputCommandParser.h"
#include <regex>
#include "MapEnum.h"
#include "InsertParagraphCommandParser.h"
#include "InsertImageCommandParser.h"
#include "SetTitleCommandParser.h"
#include "ReplaceTextCommandParser.h"
#include "ResizeImageCommandParser.h"
#include "DeleteItemCommandParser.h"
#include "SaveCommandParser.h"

using namespace command;

namespace command_parser
{
namespace
{

using namespace input_command;

unique_ptr<InputCommand> ParseInputCommand(string_view input, CommandType type)
{
	if (IsNonargCommand(type))
	{
		return make_unique<InputCommand>(InputCommand{type});
	}
	switch (type)
	{
	case CommandType::InsertParagraph:
		return ParseInsertParagraphCommand(input);
	case CommandType::InsertImage:
		return ParseInsertImageCommand(input);
	case CommandType::SetTitle:
		return ParseSetTitleCommand(input);
	case CommandType::ReplaceText:
		return ParseReplaceTextCommand(input);
	case CommandType::ResizeImage:
		return ParseResizeImageCommand(input);
	case CommandType::DeleteItem:
		return ParseDeleteItemCommand(input);
	case CommandType::Save:
		return ParseSaveCommand(input);
	}
	throw std::exception("Command parser is not implemented");
}

}

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

	regex re(R"e(^(\w+))e");
	cmatch match;
	string str(input);
	if (regex_search(str.c_str(), match, re) && match.size() > 1) {
		const string name = match[1];
		auto type = StringMapEnum(cmdNameMap, name);
		return ParseInputCommand(input, type);
	}
	throw std::exception("Invalid command string format");
}

}
