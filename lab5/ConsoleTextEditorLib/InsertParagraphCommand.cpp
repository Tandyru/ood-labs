#include "stdafx.h"
#include "InsertParagraphCommand.h"
#include "IDocumentImpl.h"

using namespace std;

namespace document
{
namespace command
{

CInsertParagraphCommand::CInsertParagraphCommand(impl::IDocumentImpl& document, optional<size_t> position, std::shared_ptr<IParagraph> paragraph)
	: m_document(document)
	, m_position(position)
	, m_paragraph(paragraph)
{
}

void CInsertParagraphCommand::ExecuteImpl()
{
	m_insertedPosition = m_position ? *m_position : m_document.GetItemsCount();
	m_document.InsertParagraph(m_paragraph, m_insertedPosition);
}

void CInsertParagraphCommand::UnexecuteImpl()
{
	m_document.DeleteItem(m_insertedPosition);
}

}
}
