#pragma once
#include "IImage.h"
#include "IResource.h"
#include "ICommandHistory.h"

namespace document
{

class CImage
	: public IImage
	, public std::enable_shared_from_this<CImage>
{
public:
	CImage(std::shared_ptr<resources::IResource> resource, int width, int height,
		const std::shared_ptr<command::ICommandHistory>& commandHistory);

	// IImage
	Path GetPath()const override;

	int GetWidth()const override;
	int GetHeight()const override;

	void Resize(int width, int height) override;

private:
	int m_width;
	int m_height;
	std::shared_ptr<resources::IResource> m_resource;
	std::shared_ptr<command::ICommandHistory> m_commandHistory;
};

}
