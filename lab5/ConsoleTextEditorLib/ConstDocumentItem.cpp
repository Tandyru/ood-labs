#include "stdafx.h"
#include "ConstDocumentItem.h"

using namespace std;

namespace document
{

CConstDocumentItem::CConstDocumentItem(shared_ptr<IImage> image)
	: m_image(image)
{
}

CConstDocumentItem::CConstDocumentItem(const shared_ptr<IParagraph>& paragraph)
	: m_paragraph(paragraph)
{
}

shared_ptr<const IImage> CConstDocumentItem::GetImage() const
{
	return m_image;
}

shared_ptr<const IParagraph> CConstDocumentItem::GetParagraph() const
{
	return m_paragraph;
}

}
