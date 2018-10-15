#pragma once
#include "IImage.h"

namespace document
{

class CImage
	: public IImage
{
public:
	CImage(Path path, int width, int height);

	// IImage
	Path GetPath()const override;

	int GetWidth()const override;
	int GetHeight()const override;

	void Resize(int width, int height) override;

private:
	int m_width;
	int m_height;
	Path m_path;
};

}
