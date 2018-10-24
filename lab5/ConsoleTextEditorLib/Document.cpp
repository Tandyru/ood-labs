#include "stdafx.h"
#include "Document.h"
#include "InsertParagraphCommand.h"

namespace document
{

CDocument::CDocument()
{
}

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text, optional<size_t> position)
{
	CheckPosition(position);
	auto command = make_unique<command::CInsertParagraphCommand>(m_impl, position, text);
	m_commandHistory.Do(move(command));
	auto lastItem = m_impl.GetItem(m_impl.GetItemsCount() - 1);
	return lastItem.GetParagraph();
}

shared_ptr<IImage> CDocument::InsertImage(const Path& path, int width, int height,
	optional<size_t> position)
{
	// TODO: make command and do it
	//auto command = make_unique<command::CInsertImageCommand>(m_impl, position, text);
	//m_commandHistory.Do(move(command));
	/*
	return InsertItem<IImage>(position, [&]() -> shared_ptr<IImage> {
		return make_shared<CImage>(path, width, height);
	});
	*/
	return shared_ptr<IImage>();
}

size_t CDocument::GetItemsCount()const
{
	return m_impl.GetItemsCount();
}

CConstDocumentItem CDocument::GetItem(size_t index)const
{
	CheckIndex(index);
	return m_impl.GetItem(index);
}

CDocumentItem CDocument::GetItem(size_t index)
{
	CheckIndex(index);
	return m_impl.GetItem(index);
}

void CDocument::DeleteItem(size_t index)
{
	CheckIndex(index);
	// TODO: make command and do it
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
	return m_commandHistory.CanUndo();
}

void CDocument::Undo()
{
	m_commandHistory.Undo();
}

bool CDocument::CanRedo()const
{
	return m_commandHistory.CanRedo();
}
void CDocument::Redo()
{
	m_commandHistory.Redo();
}

void CDocument::Save(const Path& path)const
{
	// TODO:
}

void CDocument::CheckPosition(optional<size_t> position) const
{
	if (position)
	{
		CheckIndex(*position);
	}
}

void CDocument::CheckIndex(size_t index)const
{
	if (index >= GetItemsCount())
	{
		throw CInvalidPositionException();
	}
}

}