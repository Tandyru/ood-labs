#include "stdafx.h"
#include "DocumentMock.h"

using namespace std;

shared_ptr<IParagraph> CDocumentMock::InsertParagraph(const string & text, optional<size_t> position)
{
	lastCommandText = text;
	lastCommandPosition = position;
	return shared_ptr<IParagraph>();
}

shared_ptr<IImage> CDocumentMock::InsertImage(const Path & path, int width, int height, optional<size_t> position)
{
	lastCommandPosition = position;
	return shared_ptr<IImage>();
}

size_t CDocumentMock::GetItemsCount() const
{
	return size_t();
}

CConstDocumentItem CDocumentMock::GetItem(size_t index) const
{
	return *item;
}

CDocumentItem CDocumentMock::GetItem(size_t index)
{
	return *item;
}

void CDocumentMock::DeleteItem(size_t index)
{
}

string CDocumentMock::GetTitle() const
{
	return string();
}

void CDocumentMock::SetTitle(const string & title)
{
}

bool CDocumentMock::CanUndo() const
{
	return false;
}

void CDocumentMock::Undo()
{
}

bool CDocumentMock::CanRedo() const
{
	return false;
}

void CDocumentMock::Redo()
{
}

void CDocumentMock::Save(const Path & path) const
{
}
