#include "stdafx.h"
#include "ResizeImageCommand.h"

namespace document
{
namespace command
{

CResizeImageCommand::CResizeImageCommand(impl::IDocumentImpl& document, size_t position, unsigned int width, unsigned int height)
	: m_document(document)
	, m_position(position)
	, m_width(width)
	, m_height(height)
{
}

void CResizeImageCommand::Execute()
{
	CCommand::Execute();
	auto item = m_document.GetItem(m_position);
	auto image = item.GetImage();
	if (!image)
	{
		throw runtime_error("The attempt to resize of non-image item.");
	}
	m_oldWidth = image->GetWidth();
	m_oldHeight = image->GetHeight();
	image->Resize(m_width, m_height);
}

void CResizeImageCommand::Unexecute()
{
	CCommand::Unexecute();
	auto item = m_document.GetItem(m_position);
	auto image = item.GetImage();
	if (!image)
	{
		throw runtime_error("The attempt to resize of non-image item.");
	}
	image->Resize(m_oldWidth, m_oldHeight);
}

size_t CResizeImageCommand::GetPosition() const
{
	return m_position;
}

unsigned int CResizeImageCommand::GetWidth() const
{
	return m_width;
}

unsigned int CResizeImageCommand::GetHeight() const
{
	return m_height;
}

}
}
