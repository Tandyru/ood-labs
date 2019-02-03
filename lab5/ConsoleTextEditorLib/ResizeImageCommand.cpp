#include "stdafx.h"
#include "ResizeImageCommand.h"
#include "IDocumentImpl.h"

using namespace std;

namespace document
{
namespace command
{

CResizeImageCommand::CResizeImageCommand(const std::shared_ptr<IImage>& image, unsigned int width, unsigned int height)
	: m_image(image)
	, m_width(width)
	, m_height(height)
{
}

void CResizeImageCommand::ExecuteImpl()
{
	m_oldWidth = m_image->GetWidth();
	m_oldHeight = m_image->GetHeight();
	m_image->Resize(m_width, m_height);
}

void CResizeImageCommand::UnexecuteImpl()
{
	m_image->Resize(m_oldWidth, m_oldHeight);
}

}
}
