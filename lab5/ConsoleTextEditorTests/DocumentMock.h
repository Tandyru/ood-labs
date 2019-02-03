#pragma once
#include "../ConsoleTextEditorLib/IDocument.h"

using namespace document;

class CDocumentMock : public IDocument
{
public:
	// Inherited via IDocument
	virtual std::shared_ptr<IParagraph> InsertParagraph(const std::string & text, std::optional<size_t> position = std::optional<size_t>()) override;
	virtual std::shared_ptr<IImage> InsertImage(const Path & path, int width, int height, std::optional<size_t> position = std::optional<size_t>()) override;
	virtual size_t GetItemsCount() const override;
	virtual CConstDocumentItem GetItem(size_t index) const override;
	virtual CDocumentItem GetItem(size_t index) override;
	virtual void DeleteItem(size_t index) override;
	virtual std::string GetTitle() const override;
	virtual void SetTitle(const std::string & title) override;
	virtual bool CanUndo() const override;
	virtual void Undo() override;
	virtual bool CanRedo() const override;
	virtual void Redo() override;
	virtual void Save(const Path & path) const override;

public:
	std::string lastCommandText;
	std::string lastCommandPath;
	std::optional<size_t> lastCommandPosition;
	std::unique_ptr<CDocumentItem> item;
};