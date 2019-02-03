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

	std::shared_ptr<IParagraph> InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::optional<size_t>()) override;

	std::shared_ptr<IImage> InsertImage(const Path& path, int width, int height,
		std::optional<size_t> position = std::optional<size_t>()) override;

	size_t GetItemsCount()const override;

	CConstDocumentItem GetItem(size_t index)const override;
	CDocumentItem GetItem(size_t index) override;

	void DeleteItem(size_t index) override;

	std::string GetTitle()const override;
	void SetTitle(const std::string & title) override;

	bool CanUndo()const override;
	void Undo() override;

	bool CanRedo()const override;
	void Redo() override;

	void Save(const Path& path)const override;

private:
	void CheckPosition(std::optional<size_t> position)const;
	void CheckIndex(size_t index)const;

	std::shared_ptr<IParagraph> CreateParagraph(const std::string & text);

	std::shared_ptr<IImage> CreateImage(std::unique_ptr<resources::IResource>&& path, unsigned int width, unsigned int height);

private:
	impl::CDocumentImpl m_impl;
	std::shared_ptr<command::ICommandHistory> m_commandHistory;
	resources::CDocumentResources m_resources;
};

}
