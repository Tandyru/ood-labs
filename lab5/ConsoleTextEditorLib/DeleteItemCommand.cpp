#include "stdafx.h"
#include "DeleteItemCommand.h"
#include "IDocumentImpl.h"

namespace document
{
namespace command
{

CDeleteItemCommand::CDeleteItemCommand(impl::IDocumentImpl& document, size_t position)
	: m_document(document)
	, m_position(position)
{
}

void CDeleteItemCommand::ExecuteImpl()
{
	auto item = m_document.GetItem(m_position);
	m_lastItemDeleted = m_position == (m_document.GetItemsCount() - 1);
	m_paragraph = item.GetParagraph();
	m_image = item.GetImage();
	m_document.DeleteItem(m_position);
}

void CDeleteItemCommand::UnexecuteImpl()
{
	if (bool(m_paragraph))
	{
		m_document.InsertParagraph(m_paragraph, m_position);
		m_paragraph.reset();
	}
	else if (m_image)
	{
		m_document.InsertImage(m_image, m_position);
		m_image.reset();
	}
}

}
}
