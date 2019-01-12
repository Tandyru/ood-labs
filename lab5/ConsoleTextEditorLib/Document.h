#pragma once
#include "IDocument.h"
#include "InvalidPositionException.h"
#include "DocumentImpl.h"
#include "ICommandHistory.h"
#include "DocumentResources.h"

namespace document
{

namespace command
{
class IParagraphCommandFactory;
}

class CDocument :
	public IDocument
{
public:
	CDocument();

	CDocument(const CDocument&) = delete;

	shared_ptr<IParagraph> InsertParagraph(const string& text,
		optional<size_t> position = optional<size_t>()) override;

	shared_ptr<IImage> InsertImage(const Path& path, int width, int height,
		optional<size_t> position = optional<size_t>()) override;

	size_t GetItemsCount()const override;

	CConstDocumentItem GetItem(size_t index)const override;
	CDocumentItem GetItem(size_t index) override;

	void DeleteItem(size_t index) override;

	string GetTitle()const override;
	void SetTitle(const string & title) override;

	bool CanUndo()const override;
	void Undo() override;

	bool CanRedo()const override;
	void Redo() override;

	void Save(const Path& path)const override;

private:
	void CheckPosition(optional<size_t> position)const;
	void CheckIndex(size_t index)const;

	shared_ptr<IParagraph> CreateParagraph(const string & text);

	shared_ptr<IImage> CreateImage(shared_ptr<resources::IResource> path, unsigned int width, unsigned int height);

private:
	impl::CDocumentImpl m_impl;
	shared_ptr<command::ICommandHistory> m_commandHistory;
	resources::CDocumentResources m_resources;
	shared_ptr<command::IParagraphCommandFactory> m_paragraphCommandFactory;
	shared_ptr<command::IImageCommandFactory> m_imageCommandFactory;
};

}
