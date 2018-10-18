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

namespace command_parser
{
namespace
{

using namespace input_command;

unique_ptr<InputCommand> ParseInputCommand(string_view input, InputCommandType type)
{
	if (IsNonargCommand(type))
	{
		return make_unique<InputCommand>(InputCommand{type});
	}
	switch (type)
	{
	case InputCommandType::InsertParagraph:
		return ParseInsertParagraphCommand(input);
	case InputCommandType::InsertImage:
		return ParseInsertImageCommand(input);
	case InputCommandType::SetTitle:
		return ParseSetTitleCommand(input);
	case InputCommandType::ReplaceText:
		return ParseReplaceTextCommand(input);
	case InputCommandType::ResizeImage:
		return ParseResizeImageCommand(input);
	case InputCommandType::DeleteItem:
		return ParseDeleteItemCommand(input);
	case InputCommandType::Save:
		return ParseSaveCommand(input);
	}
	throw std::exception("Command parser is not implemented");
}

}

unique_ptr<input_command::InputCommand> ParseInputCommand(string_view input)
{
	static pair<const char*, InputCommandType> cmdNameMap[] =
	{
		{ "InsertParagraph", InputCommandType::InsertParagraph },
		{ "InsertImage", InputCommandType::InsertImage },
		{ "SetTitle", InputCommandType::SetTitle },
		{ "List", InputCommandType::List },
		{ "ReplaceText", InputCommandType::ReplaceText },
		{ "ResizeImage", InputCommandType::ResizeImage },
		{ "DeleteItem", InputCommandType::DeleteItem },
		{ "Help", InputCommandType::Help },
		{ "Undo", InputCommandType::Undo },
		{ "Redo", InputCommandType::Redo },
		{ "Save", InputCommandType::Save },
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
