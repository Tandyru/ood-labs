#include "stdafx.h"
#include "InsertImageCommand.h"

namespace document
{
namespace command
{

CInsertImageCommand::CInsertImageCommand(impl::IDocumentImpl & document, optional<size_t> position, 
	unsigned int width, unsigned int height, unique_ptr<resources::IResource>&& resource)
	: m_document(document)
	, m_position(position)
	, m_width(width)
	, m_height(height)
	, m_resource(move(resource))
{
}

void CInsertImageCommand::ExecuteImpl()
{
	m_insertedPosition = m_position ? *m_position : m_document.GetItemsCount();
	m_document.InsertImage(m_resource, m_width, m_height, m_position);
}

void CInsertImageCommand::UnexecuteImpl()
{
	m_document.DeleteItem(m_insertedPosition);
}

}
}
