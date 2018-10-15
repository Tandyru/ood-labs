#pragma once
#include "IDocument.h"
#include "InvalidPositionException.h"

namespace document
{

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
	template<typename OI>
	inline shared_ptr<OI> InsertItem(optional<size_t> position, const function<shared_ptr<OI>()>& itemFactory)
	{
		if (position && *position > m_items.size())
		{
			throw CInvalidPositionException();
		}
		const auto it = position ? next(m_items.cbegin(), *position) : m_items.cend();
		const auto content = itemFactory();
		m_items.emplace(it, make_shared<CDocumentItem>(content));
		return content;
	}

	void CheckIndex(size_t index)const;

private:
	vector<shared_ptr<CDocumentItem>> m_items;
	string m_title;
};

}
