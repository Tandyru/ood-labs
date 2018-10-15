#include "stdafx.h"
#include "Document.h"

namespace document
{

Document::Document()
{
}

shared_ptr<IParagraph> Document::InsertParagraph(const string& text,
	optional<size_t> position)
{
	// TODO:
	return shared_ptr<IParagraph>();
}

shared_ptr<IImage> Document::InsertImage(const Path& path, int width, int height,
	optional<size_t> position)
{
	// TODO:
	return shared_ptr<IImage>();
}

size_t Document::GetItemsCount()const
{
	// TODO:
	return 0;
}

CConstDocumentItem Document::GetItem(size_t index)const
{
	// TODO:
	return CConstDocumentItem(shared_ptr<IImage>());
}

CDocumentItem Document::GetItem(size_t index)
{
	// TODO:
	return CDocumentItem(shared_ptr<IImage>());
}

void Document::DeleteItem(size_t index)
{
	// TODO:
}

string Document::GetTitle()const
{
	return m_title;
}

void Document::SetTitle(const string & title)
{
	m_title = title;
}

bool Document::CanUndo()const
{
	// TODO:
	return false;
}

void Document::Undo()
{
	// TODO:
}

bool Document::CanRedo()const
{
	// TODO:
	return false;
}
void Document::Redo()
{
	// TODO:
}

void Document::Save(const Path& path)const
{
	// TODO:
}

}