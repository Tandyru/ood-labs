#include "stdafx.h"
#include "InsertImageCommand.h"
#include "ICommandVisitor.h"

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

void CInsertImageCommand::Execute()
{
	CCommand::Execute();
	m_insertedPosition = m_position ? *m_position : m_document.GetItemsCount();
	m_document.InsertImage(m_resource, m_width, m_height, m_position);
}

void CInsertImageCommand::Unexecute()
{
	CCommand::Unexecute();
	m_document.DeleteItem(m_insertedPosition);
}

optional<size_t> CInsertImageCommand::GetPosition() const
{
	return m_position;
}

Path CInsertImageCommand::GetPath() const
{
	return m_resource->GetFilePath();
}

shared_ptr<resources::IResource> CInsertImageCommand::GetResource() const
{
	return m_resource;
}

}
}
