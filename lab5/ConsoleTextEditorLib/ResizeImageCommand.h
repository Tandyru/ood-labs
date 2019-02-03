#pragma once
#include "Command.h"
#include "IImage.h"

namespace document
{
namespace command
{

class CResizeImageCommand : public CCommand
{
public:
	CResizeImageCommand(const std::shared_ptr<IImage>& image, unsigned int width, unsigned int height);

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	std::shared_ptr<IImage> m_image;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_oldWidth = 0;
	unsigned int m_oldHeight = 0;
};

}
}
