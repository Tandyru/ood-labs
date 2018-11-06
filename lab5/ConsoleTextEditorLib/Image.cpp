#include "stdafx.h"
#include "Image.h"

namespace document
{

CImage::CImage(shared_ptr<resources::IResource> resource, int width, int height)
	: m_resource(resource)
	, m_width(width)
	, m_height(height)
{
}

Path CImage::GetPath() const
{
	return m_resource->GetSavePath();
}

int CImage::GetWidth() const
{
	return m_width;
}

int CImage::GetHeight() const
{
	return m_height;
}

void CImage::Resize(int width, int height)
{
	if (m_onBeforeResize)
	{
		m_onBeforeResize(*this, width, height);
	}
	m_width = width;
	m_height = height;
}

void CImage::SetOnBeforeResize(const BeforeResizeHandler & handler)
{
	m_onBeforeResize = handler;
}

}
