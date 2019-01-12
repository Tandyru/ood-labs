#pragma once
#include "IImage.h"
#include "ResizeImageCommand.h"
#include "IImageCommandFactory.h"
#include "IDocumentImpl.h"

namespace document
{
namespace command
{

class CImageCommandFactory : public IImageCommandFactory
{
public:
	CImageCommandFactory(impl::IDocumentImpl& document);

	unique_ptr<CResizeImageCommand> CreateResizeImageCommand(const IImage & image, unsigned int width, unsigned int height) override;

private:
	impl::IDocumentImpl& m_document;
};

}
}
