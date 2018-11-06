#pragma once
#include "IImage.h"
#include "IResource.h"

namespace document
{

class CImage
	: public IImage
{
public:
	using BeforeResizeHandler = std::function<void(const IImage&, unsigned int, unsigned int)>;

	CImage(shared_ptr<resources::IResource> resource, int width, int height);

	// IImage
	Path GetPath()const override;

	int GetWidth()const override;
	int GetHeight()const override;

	void Resize(int width, int height) override;

	void SetOnBeforeResize(const BeforeResizeHandler & handler);

private:
	int m_width;
	int m_height;
	shared_ptr<resources::IResource> m_resource;
	BeforeResizeHandler m_onBeforeResize;
};

}
