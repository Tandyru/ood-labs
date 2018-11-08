#pragma once
#include "../ConsoleTextEditorLib/IDocument.h"

using namespace document;

class CDocumentMock : public IDocument
{
public:
	// Inherited via IDocument
	virtual shared_ptr<IParagraph> InsertParagraph(const string & text, optional<size_t> position = optional<size_t>()) override;
	virtual shared_ptr<IImage> InsertImage(const Path & path, int width, int height, optional<size_t> position = optional<size_t>()) override;
	virtual size_t GetItemsCount() const override;
	virtual CConstDocumentItem GetItem(size_t index) const override;
	virtual CDocumentItem GetItem(size_t index) override;
	virtual void DeleteItem(size_t index) override;
	virtual string GetTitle() const override;
	virtual void SetTitle(const string & title) override;
	virtual bool CanUndo() const override;
	virtual void Undo() override;
	virtual bool CanRedo() const override;
	virtual void Redo() override;
	virtual void Save(const Path & path) const override;

public:
	string lastCommandText;
	string lastCommandPath;
	optional<size_t> lastCommandPosition;
	unique_ptr<CDocumentItem> item;
};