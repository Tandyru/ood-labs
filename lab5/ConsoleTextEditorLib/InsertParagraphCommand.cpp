#include "stdafx.h"
#include "InsertParagraphCommand.h"
#include "ICommandVisitor.h"

namespace document
{
namespace command
{

CInsertParagraphCommand::CInsertParagraphCommand(impl::IDocumentImpl& document, optional<size_t> position, const string& text)
	: CCommand(CommandType::InsertParagraph, document)
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

void CInsertParagraphCommand::Accept(ICommandVisitor & visitor) const
{
	visitor.Visit(*this);
}

size_t CInsertParagraphCommand::GetInsertedPosition() const
{
	assert(m_executed);
	return m_insertedPosition;
}

string CInsertParagraphCommand::GetText() const
{
	return m_text;
}

}
}
