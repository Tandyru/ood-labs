#include "stdafx.h"
#include "DocumentToHtmlConvertor.h"
#include "HtmlUtils.h"

namespace document
{
namespace html
{

namespace
{


}

void ConvertDocumentToHtml(const impl::IDocumentImpl & document, const Path & htmlFilePath)
{
	// ??
}

void ConvertDocumentToHtml(const impl::IDocumentImpl & document, ostream & out)
{
	out << GetHtmlDocumentHeader(document.GetTitle());
	auto count = document.GetItemsCount();
	for (decltype(count) index = 0; index < count; index++)
	{
		auto item = document.GetItem(index);
		auto paragraph = item.GetParagraph();

		// ??
	}
	out << GetHtmlDocumentFooter();
	// ??
}

}
}
