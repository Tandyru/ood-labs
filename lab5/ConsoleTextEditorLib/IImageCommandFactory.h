#pragma once
#include "IImage.h"

namespace document
{
namespace command
{

class CResizeImageCommand;

class IImageCommandFactory
{
public:
	virtual std::unique_ptr<CResizeImageCommand> CreateResizeImageCommand(const IImage & image, unsigned int width, unsigned int height) = 0;

	virtual ~IImageCommandFactory() = default;
};

}
}
