#include "stdafx.h"
#include "Document.h"
#include "Paragraph.h"
#include "Image.h"

namespace document
{
namespace impl
{

CDocumentImpl::CDocumentImpl()
{
}

shared_ptr<IParagraph> CDocumentImpl::InsertParagraph(const string& text,
	optional<size_t> position)
{
	return InsertItem<IParagraph>(position, [&]() -> shared_ptr<IParagraph> {
		return make_shared<CParagraph>(text);
	});
}

shared_ptr<IImage> CDocumentImpl::InsertImage(const Path& path, int width, int height,
	optional<size_t> position)
{
	return InsertItem<IImage>(position, [&]() -> shared_ptr<IImage> {
		return make_shared<CImage>(path, width, height);
	});
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

void CDocumentImpl::CheckIndex(size_t index)const
{
	if (index >= m_items.size())
	{
		throw CInvalidPositionException();
	}
}

}
}
