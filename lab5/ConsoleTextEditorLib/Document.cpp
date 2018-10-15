#include "stdafx.h"
#include "Document.h"
#include "Paragraph.h"
#include "Image.h"

namespace document
{

CDocument::CDocument()
{
}

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text,
	optional<size_t> position)
{
	return InsertItem<IParagraph>(position, [&]() -> shared_ptr<IParagraph> {
		return make_shared<CParagraph>(text);
	});
}

shared_ptr<IImage> CDocument::InsertImage(const Path& path, int width, int height,
	optional<size_t> position)
{
	return InsertItem<IImage>(position, [&]() -> shared_ptr<IImage> {
		return make_shared<CImage>(path, width, height);
	});
}

size_t CDocument::GetItemsCount()const
{
	return m_items.size();
}

CConstDocumentItem CDocument::GetItem(size_t index)const
{
	CheckIndex(index);
	return *m_items[index];
}

CDocumentItem CDocument::GetItem(size_t index)
{
	CheckIndex(index);
	return *m_items[index];
}

void CDocument::DeleteItem(size_t index)
{
	CheckIndex(index);
	m_items.erase(m_items.begin() + index);
}

string CDocument::GetTitle()const
{
	return m_title;
}

void CDocument::SetTitle(const string & title)
{
	m_title = title;
}

bool CDocument::CanUndo()const
{
	// TODO:
	return false;
}

void CDocument::Undo()
{
	// TODO:
}

bool CDocument::CanRedo()const
{
	// TODO:
	return false;
}
void CDocument::Redo()
{
	// TODO:
}

void CDocument::Save(const Path& path)const
{
	// TODO:
}

void CDocument::CheckIndex(size_t index)const
{
	if (index >= m_items.size())
	{
		throw CInvalidPositionException();
	}
}

}