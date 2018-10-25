#include "stdafx.h"
#include "InsertImageCommand.h"
#include "ICommandVisitor.h"

namespace document
{
namespace command
{

CInsertImageCommand::CInsertImageCommand(impl::IDocumentImpl & document, optional<size_t> position, unsigned int width, unsigned int height, Path path)
	: CCommand(CommandType::InsertImage, document)
	, m_position(position)
	, m_width(width)
	, m_height(height)
	, m_path(path)
{
}

void CInsertImageCommand::Execute()
{
	CCommand::Execute();
	m_insertedPosition = m_position ? *m_position : m_document.GetItemsCount();
	m_document.InsertImage(m_path, m_width, m_height, m_position);
}

void CInsertImageCommand::Unexecute()
{
	CCommand::Unexecute();
	m_document.DeleteItem(m_insertedPosition);
}

void CInsertImageCommand::Accept(ICommandVisitor & visitor) const
{
	visitor.Visit(*this);
}

size_t CInsertImageCommand::GetInsertedPosition() const
{
	assert(m_executed);
	return m_insertedPosition;
}

}
}
