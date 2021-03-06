#include "stdafx.h"
#include "Document.h"
#include "InsertParagraphCommand.h"
#include "InsertImageCommand.h"
#include "DeleteItemCommand.h"
#include "SetTitleCommand.h"
#include "ResizeImageCommand.h"
#include "DocumentToHtmlConvertor.h"
#include "CommandHistory.h"

namespace document
{

using namespace std;
using namespace command;
using namespace std::placeholders;

CDocument::CDocument()
	: m_commandHistory(make_shared<CCommandHistory>())
{
}

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text, optional<size_t> position)
{
	CheckPosition(position);
	auto paragraph = CreateParagraph(text);
	auto command = make_unique<command::CInsertParagraphCommand>(m_impl, position, paragraph);
	m_commandHistory->Do(move(command));
	auto lastItem = m_impl.GetItem(m_impl.GetItemsCount() - 1);
	return lastItem.GetParagraph();
}

shared_ptr<IImage> CDocument::InsertImage(const Path& path, int width, int height,
	optional<size_t> position)
{
	CheckPosition(position);
	const auto saveNamePrefix = "image";
	auto resource = m_resources.AddResource(path, saveNamePrefix);
	auto image = CreateImage(move(resource), width, height);
	auto command = make_unique<command::CInsertImageCommand>(m_impl, position, image);
	m_commandHistory->Do(move(command));
	auto lastItem = m_impl.GetItem(m_impl.GetItemsCount() - 1);
	return lastItem.GetImage();
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
	auto command = make_unique<command::CDeleteItemCommand>(m_impl, index);
	m_commandHistory->Do(move(command));
}

string CDocument::GetTitle()const
{
	return m_impl.GetTitle();
}

void CDocument::SetTitle(const string & title)
{
	auto command = make_unique<command::CSetTitleCommand>(m_impl, title);
	m_commandHistory->Do(move(command));
}

bool CDocument::CanUndo()const
{
	return m_commandHistory->CanUndo();
}

void CDocument::Undo()
{
	m_commandHistory->Undo();
}

bool CDocument::CanRedo()const
{
	return m_commandHistory->CanRedo();
}

void CDocument::Redo()
{
	m_commandHistory->Redo();
}

void CDocument::Save(const Path& path)const
{
	html::ConvertDocumentToHtml(m_impl, path);
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
	if (index > GetItemsCount())
	{
		throw CInvalidPositionException();
	}
}

shared_ptr<IParagraph> CDocument::CreateParagraph(const string& text)
{
	return make_shared<CParagraph>(text, m_commandHistory);
}

shared_ptr<IImage> CDocument::CreateImage(unique_ptr<resources::IResource>&& resource, unsigned int width, unsigned int height)
{
	return make_shared<CImage>(move(resource), width, height, m_commandHistory);
}

}