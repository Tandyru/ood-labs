#pragma once
#include "IDocument.h"

namespace document
{

class Document :
	public IDocument
{
public:
	Document();

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
	vector<shared_ptr<CDocumentItem>> m_items;
	string m_title;
};

}
