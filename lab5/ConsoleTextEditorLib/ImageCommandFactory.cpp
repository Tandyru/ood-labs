#include "stdafx.h"
#include "ImageCommandFactory.h"
#include "ResizeImageCommand.h"

using namespace std;

namespace document
{
namespace command
{

CImageCommandFactory::CImageCommandFactory(impl::IDocumentImpl & document)
	: m_document(document)
{
}

unique_ptr<CResizeImageCommand> CImageCommandFactory::CreateResizeImageCommand(const IImage & image, unsigned int width, unsigned int height)
{
	auto position = m_document.GetImagePosition(image);
	return make_unique<command::CResizeImageCommand>(m_document, position, width, height);
}

}
}
