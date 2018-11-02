#include "stdafx.h"
#include "InsertParagraphCommand.h"
#include "ICommandVisitor.h"

namespace document
{
namespace command
{

CInsertParagraphCommand::CInsertParagraphCommand(impl::IDocumentImpl& document, optional<size_t> position, const string& text)
	: m_document(document)
	, m_position(position)
	, m_text(text)
{
}

void CInsertParagraphCommand::Execute()
{
	CCommand::Execute();
	m_insertedPosition = m_position ? *m_position : m_document.GetItemsCount();
	m_document.InsertParagraph(m_text, m_insertedPosition);
}

void CInsertParagraphCommand::Unexecute()
{
	CCommand::Unexecute();
	m_document.DeleteItem(m_insertedPosition);
}

optional<size_t> CInsertParagraphCommand::GetPosition() const
{
	return m_position;
}

string CInsertParagraphCommand::GetText() const
{
	return m_text;
}

}
}
