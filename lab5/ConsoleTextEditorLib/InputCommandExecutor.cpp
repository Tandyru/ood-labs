#include "stdafx.h"
#include "InputCommandExecutor.h"
#include "InvalidPositionException.h"
#include "ConstDocumentItem.h"
#include "DocumentDumper.h"
#include "Exception.h"
#include "ExitException.h"

using namespace std;

namespace input_command
{

CInputCommandExecutor::CInputCommandExecutor(document::IDocument & document, ostream& out,
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
		DumpDocument(m_document, m_out);
		break;
	case InputCommandType::Undo:
		if (m_document.CanUndo())
		{
			m_document.Undo();
		}
		else
		{
			throw Exception("Cannot undo.");
		}
		break;
	case InputCommandType::Redo:
		if (m_document.CanRedo())
		{
			m_document.Redo();
		}
		else
		{
			throw Exception("Cannot redo.");
		}
		break;
	case InputCommandType::Exit:
		throw ExitException();
	default:
		throw runtime_error("ExecuteNonArgCommand is called for a command with argument(s) or no handler for the command.");
	}
}

namespace
{

optional<size_t> ConvertPosition(Position position)
{
	//return position != END_POSITION ? position : optional<size_t>();
	return position;
}

}

void CInputCommandExecutor::ExecuteCommand(const InsertParagraphInputCommand & command)
{
	m_document.InsertParagraph(command.text, ConvertPosition(command.position));
}

void CInputCommandExecutor::ExecuteCommand(const InsertImageInputCommand & command)
{
	m_document.InsertImage(command.path, command.width, command.height, ConvertPosition(command.position));
}

void CInputCommandExecutor::ExecuteCommand(const SetTitleInputCommand & command)
{
	m_document.SetTitle(command.title);
}

void CInputCommandExecutor::ExecuteCommand(const ReplaceTextInputCommand & command)
{
	if (command.position == END_POSITION)
	{
		throw document::CInvalidPositionException();
	}
	auto item = m_document.GetItem(*command.position);
	auto paragraph = item.GetParagraph();
	if (!paragraph)
	{
		throw Exception("Cannot replace text of non-paragraph item.");
	}
	paragraph->SetText(command.text);
}

void CInputCommandExecutor::ExecuteCommand(const ResizeImageInputCommand & command)
{
	auto position = command.position;
	if (position == END_POSITION)
	{
		throw document::CInvalidPositionException();
	}
	auto item = m_document.GetItem(*position);
	auto image = item.GetImage();
	if (!image)
	{
		throw exception("The item in the position is not an image.");
	}
	image->Resize(command.width, command.height);
}

void CInputCommandExecutor::ExecuteCommand(const DeleteItemInputCommand & command)
{
	if (command.position == END_POSITION)
	{
		throw document::CInvalidPositionException();
	}
	m_document.DeleteItem(*command.position);
}

void CInputCommandExecutor::ExecuteCommand(const SaveInputCommand & command)
{
	m_document.Save(command.path);
}

}
