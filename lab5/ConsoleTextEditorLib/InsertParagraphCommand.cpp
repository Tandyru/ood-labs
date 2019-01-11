#include "stdafx.h"
#include "InsertParagraphCommand.h"

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

void CInsertParagraphCommand::ExecuteImpl()
{
	m_insertedPosition = m_position ? *m_position : m_document.GetItemsCount();
	m_document.InsertParagraph(m_text, m_insertedPosition);
}

void CInsertParagraphCommand::UnexecuteImpl()
{
	m_document.DeleteItem(m_insertedPosition);
}

}
}
