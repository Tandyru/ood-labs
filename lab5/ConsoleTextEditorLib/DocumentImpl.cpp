#include "stdafx.h"
#include "Document.h"
#include "Paragraph.h"
#include "Image.h"

using namespace std;

namespace document
{
namespace impl
{

CDocumentImpl::CDocumentImpl(const ParagraphFactory & paragraphFactory, const ImageFactory & imageFactory)
	: m_paragraphFactory(paragraphFactory)
	, m_imageFactory(imageFactory)
{
}

void CDocumentImpl::InsertParagraph(const std::shared_ptr<IParagraph>& paragraph, std::optional<size_t> position)
{
	InsertItem<IParagraph>(position, paragraph);
}

void CDocumentImpl::InsertImage(shared_ptr<resources::IResource> resource, int width, int height,
	optional<size_t> position)
{
	InsertItem<IImage>(position, m_imageFactory(resource, width, height));
}

void CDocumentImpl::InsertImage(shared_ptr<IImage> image, size_t position)
{
	InsertItem<IImage>(position, image);
}

size_t CDocumentImpl::GetItemsCount()const
{
	return m_items.size();
}

CConstDocumentItem CDocumentImpl::GetItem(size_t index)const
{
	CheckIndex(index);
	return *m_items[index];
}

CDocumentItem CDocumentImpl::GetItem(size_t index)
{
	CheckIndex(index);
	return *m_items[index];
}

void CDocumentImpl::DeleteItem(size_t index)
{
	CheckIndex(index);
	m_items.erase(m_items.begin() + index);
}

void CDocumentImpl::SetTitle(const string & title)
{
	m_title = title;
}

string CDocumentImpl::GetTitle() const
{
	return m_title;
}

void CDocumentImpl::CheckIndex(size_t index)const
{
	if (index >= m_items.size())
	{
		throw CInvalidPositionException();
	}
}

size_t CDocumentImpl::GetItemPosition(const std::function<bool(const CConstDocumentItem&)>& pred) const
{
	for (size_t index = 0; index < m_items.size(); index++)
	{
		auto item = m_items[index];
		if (pred(*item))
		{
			return index;
		}
	}
	throw std::logic_error("Document item not found");
}

size_t CDocumentImpl::GetImagePosition(const IImage & image) const
{
	return GetItemPosition([&](const CConstDocumentItem& item) {
		auto imageOfItem = item.GetImage();
		if (imageOfItem)
		{
			if (imageOfItem.get() == &image)
			{
				return true;
			}
		}
		return false;
	});
}

}
}
