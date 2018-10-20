#include "stdafx.h"
#include "InsertParagraphInputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

InsertParagraphInputCommand::InsertParagraphInputCommand(command::Position position, string text)
	: InputCommand(InputCommandType::InsertParagraph)
	, position(position)
	, text(text)
{

}

void InsertParagraphInputCommand::Execute(IInputCommandExecutor & executor)
{
	executor.ExecuteCommand(*this);
}

}
