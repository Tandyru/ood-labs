#include "stdafx.h"
#include "Image.h"
#include "ResizeImageCommand.h"

using namespace std;

namespace document
{

CImage::CImage(shared_ptr<resources::IResource> resource, int width, int height, 
	const shared_ptr<command::ICommandHistory>& commandHistory,
	const shared_ptr<command::IImageCommandFactory> & commandFactory)
	: m_resource(resource)
	, m_width(width)
	, m_height(height)
	, m_commandHistory(commandHistory)
	, m_commandFactory(commandFactory)
{
}

Path CImage::GetPath() const
{
	return m_resource->GetFilePath();
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
	if (m_commandHistory && m_commandHistory->ShouldCreateCommand())
	{
		auto command = m_commandFactory->CreateResizeImageCommand(*this, width, height);
		m_commandHistory->Do(move(command));
	}
	m_width = width;
	m_height = height;
}

}
