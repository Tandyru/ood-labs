#include "stdafx.h"
#include "Image.h"
#include "ResizeImageCommand.h"

using namespace std;

namespace document
{

CImage::CImage(shared_ptr<resources::IResource> resource, int width, int height, 
	const shared_ptr<command::ICommandHistory>& commandHistory)
	: m_resource(resource)
	, m_width(width)
	, m_height(height)
	, m_commandHistory(commandHistory)
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
		auto command = make_unique<command::CResizeImageCommand>(shared_from_this(), width, height);
		m_commandHistory->Do(move(command));
	}
	m_width = width;
	m_height = height;
}

}
