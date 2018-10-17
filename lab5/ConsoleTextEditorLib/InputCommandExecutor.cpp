#include "stdafx.h"
#include "InputCommandExecutor.h"

namespace input_command
{

CInputCommandExecutor::CInputCommandExecutor(shared_ptr<document::IDocument> document, ostream& out, 
	const HelpCommandHandler& helpHandler)
	: m_document(document)
	, m_out(out)
	, m_helpHandler(helpHandler)
{
}

void CInputCommandExecutor::ExecuteCommand(InputCommandType type)
{
	switch (type)
	{
	case InputCommandType::Help:
		m_helpHandler(m_out);
		break;
	case InputCommandType::List:
	case InputCommandType::Undo:
	case InputCommandType::Redo:
	default:
		throw runtime_error("ExecuteNonArgCommand is called for a command with argument(s) or no handler for the command.");
	}
}

void CInputCommandExecutor::ExecuteInsertParagraphCommand(const InsertParagraphInputCommand & command)
{
}

void CInputCommandExecutor::ExecuteInsertImageCommand(const InsertImageInputCommand & command)
{
}

void CInputCommandExecutor::ExecuteSetTitleCommand(const SetTitleInputCommand & command)
{
}

void CInputCommandExecutor::ExecuteReplaceTextCommand(const ReplaceTextInputCommand & command)
{
}

void CInputCommandExecutor::ExecuteResizeImageCommand(const ResizeImageInputCommand & command)
{
}

void CInputCommandExecutor::ExecuteDeleteItemCommand(const DeleteItemInputCommand & command)
{
}

void CInputCommandExecutor::ExecuteSaveCommand(const SaveInputCommand & command)
{
}

}
