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

void CResizeImageCommand::ExecuteImpl()
{
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

void CResizeImageCommand::UnexecuteImpl()
{
	auto item = m_document.GetItem(m_position);
	auto image = item.GetImage();
	if (!image)
	{
		throw runtime_error("The attempt to resize of non-image item.");
	}
	image->Resize(m_oldWidth, m_oldHeight);
}

}
}
