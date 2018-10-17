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

class IInputCommandExecutor
{
public:
	virtual void ExecuteCommand(InputCommandType type) = 0;
	virtual void ExecuteInsertParagraphCommand(const InsertParagraphInputCommand& command) = 0;
	virtual void ExecuteInsertImageCommand(const InsertImageInputCommand& command) = 0;
	virtual void ExecuteSetTitleCommand(const SetTitleInputCommand& command) = 0;
	virtual void ExecuteReplaceTextCommand(const ReplaceTextInputCommand& command) = 0;
	virtual void ExecuteResizeImageCommand(const ResizeImageInputCommand& command) = 0;
	virtual void ExecuteDeleteItemCommand(const DeleteItemInputCommand& command) = 0;
	virtual void ExecuteSaveCommand(const SaveInputCommand& command) = 0;
	virtual ~IInputCommandExecutor() = default;
};

}
