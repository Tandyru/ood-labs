#include "stdafx.h"
#include "InputCommandExecutor.h"

namespace input_command
{

CInputCommandExecutor::CInputCommandExecutor(IDocumentCommandFactory & documentCommandFactory, ostream& out,
	const HelpCommandHandler& helpHandler)
	: m_document(document)
	, m_out(out)
	, m_helpHandler(helpHandler)
{
	assert(m_document);
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

namespace
{

optional<size_t> ConvertPosition(command::Position position)
{
	return position != command::END_POSITION ? position : optional<size_t>();
}

}

void CInputCommandExecutor::ExecuteCommand(const InsertParagraphInputCommand & command)
{
	m_document->InsertParagraph(command.text, ConvertPosition(command.position));
}

void CInputCommandExecutor::ExecuteCommand(const InsertImageInputCommand & command)
{
	m_document->InsertImage(command.path, command.width, command.height, ConvertPosition(command.position));
}

void CInputCommandExecutor::ExecuteCommand(const SetTitleInputCommand & command)
{
	m_document->SetTitle(command.title);
}

void CInputCommandExecutor::ExecuteCommand(const ReplaceTextInputCommand & command)
{
	//m_document->Repla
}

void CInputCommandExecutor::ExecuteCommand(const ResizeImageInputCommand & command)
{
}

void CInputCommandExecutor::ExecuteCommand(const DeleteItemInputCommand & command)
{
}

void CInputCommandExecutor::ExecuteCommand(const SaveInputCommand & command)
{
}

}
