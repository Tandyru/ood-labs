#include "stdafx.h"
#include "DocumentItem.h"

using namespace std;

namespace document
{

CDocumentItem::CDocumentItem(shared_ptr<IImage> image)
	: CConstDocumentItem(image)
{
}

CDocumentItem::CDocumentItem(const shared_ptr<IParagraph>& paragraph)
	: CConstDocumentItem(paragraph)
{
}

shared_ptr<IImage> CDocumentItem::GetImage()
{
	return m_image;
}

shared_ptr<IParagraph> CDocumentItem::GetParagraph()
{
	return m_paragraph;
}

}
