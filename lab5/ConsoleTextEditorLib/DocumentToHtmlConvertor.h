#pragma once
#include "IDocumentImpl.h"

namespace document
{
namespace html
{

void ConvertDocumentToHtml(const impl::IDocumentImpl& document, const Path& htmlFilePath);
void ConvertDocumentToHtml(const impl::IDocumentImpl& document, std::ostream& out, const Path & imagesDirectory);

}
}