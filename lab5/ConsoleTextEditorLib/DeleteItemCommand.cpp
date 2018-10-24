#include "stdafx.h"
#include "DeleteItemCommand.h"
#include "ICommandVisitor.h"

namespace document
{
namespace command
{

CDeleteItemCommand::CDeleteItemCommand(impl::IDocumentImpl& document, size_t position)
	: CCommand(CommandType::DeleteItem, document)
	, m_position(position)
{
}

void CDeleteItemCommand::Execute()
{
	CCommand::Execute();
	auto item = m_document.GetItem(m_position);
	m_paragraph = item.GetParagraph();
	m_image = item.GetImage();
	m_document.DeleteItem(m_position);
}

void CDeleteItemCommand::Unexecute()
{
	CCommand::Unexecute();
	if (m_paragraph)
	{
		m_document.InsertParagraph(m_paragraph->GetText(), m_position);
		m_paragraph.reset();
	}
	else if (m_image)
	{
		m_document.InsertImage(m_image->GetPath(), m_image->GetWidth(), m_image->GetHeight(), m_position);
		m_image.reset();
	}
}

void CDeleteItemCommand::Accept(ICommandVisitor & visitor) const
{
	visitor.Visit(*this);
}

size_t CDeleteItemCommand::GetPosition() const
{
	return m_position;
}

shared_ptr<IParagraph> CDeleteItemCommand::GetDeletedParagraph() const
{
	return m_paragraph;
}

shared_ptr<IImage> CDeleteItemCommand::GetDeletedImage() const
{
	return m_image;
}

}
}
