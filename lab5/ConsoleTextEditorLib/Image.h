#pragma once
#include "IImage.h"
#include "IResource.h"
#include "ICommandHistory.h"
#include "IImageCommandFactory.h"

namespace document
{

class CImage
	: public IImage
{
public:
	using BeforeResizeHandler = std::function<void(const IImage&, unsigned int, unsigned int)>;

	CImage(shared_ptr<resources::IResource> resource, int width, int height,
		const shared_ptr<command::ICommandHistory>& commandHistory,
		const shared_ptr<command::IImageCommandFactory> & commandFactory);

	// IImage
	Path GetPath()const override;

	int GetWidth()const override;
	int GetHeight()const override;

	void Resize(int width, int height) override;

private:
	int m_width;
	int m_height;
	shared_ptr<resources::IResource> m_resource;
	shared_ptr<command::ICommandHistory> m_commandHistory;
	shared_ptr<command::IImageCommandFactory> m_commandFactory;
};

}
