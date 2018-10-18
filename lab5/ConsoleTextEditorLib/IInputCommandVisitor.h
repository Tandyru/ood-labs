#pragma once
#include "InputCommandType.h"
#include "InputCommand.h"
#include "SaveInputCommand.h"
#include "InsertParagraphInputCommand.h"
#include "InsertImageInputCommand.h"
#include "SetTitleInputCommand.h"
#include "ReplaceTextInputCommand.h"
#include "ResizeImageInputCommand.h"
#include "DeleteItemInputCommand.h"

namespace input_command
{

class IInputCommandVisitor
{
public:
	virtual void ExecuteCommand(InputCommandType type) = 0;
	virtual void ExecuteCommand(const InsertParagraphInputCommand& command) = 0;
	virtual void ExecuteCommand(const InsertImageInputCommand& command) = 0;
	virtual void ExecuteCommand(const SetTitleInputCommand& command) = 0;
	virtual void ExecuteCommand(const ReplaceTextInputCommand& command) = 0;
	virtual void ExecuteCommand(const ResizeImageInputCommand& command) = 0;
	virtual void ExecuteCommand(const DeleteItemInputCommand& command) = 0;
	virtual void ExecuteCommand(const SaveInputCommand& command) = 0;
	virtual ~IInputCommandVisitor() = default;
};

}
