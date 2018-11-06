#pragma once
#include "IDocumentImpl.h"
#include "InvalidPositionException.h"

namespace document
{
namespace impl
{

class CDocumentImpl :
	public IDocumentImpl
{
public:
	using ParagraphFactory = std::function<shared_ptr<IParagraph>(const string& text)>;
	using ImageFactory = std::function<shared_ptr<IImage>(shared_ptr<resources::IResource> resource, unsigned int width, unsigned int height)>;
	CDocumentImpl(const ParagraphFactory & paragraphFactory, const ImageFactory & imageFactory);

	CDocumentImpl(const CDocumentImpl&) = delete;

	shared_ptr<IParagraph> InsertParagraph(const string& text,
		optional<size_t> position = optional<size_t>()) override;

	shared_ptr<IImage> InsertImage(shared_ptr<resources::IResource> resource, int width, int height,
		optional<size_t> position = optional<size_t>()) override;

	void InsertImage(shared_ptr<IImage> image, size_t position) override;

	size_t GetItemsCount()const override;

	CConstDocumentItem GetItem(size_t index)const override;
	CDocumentItem GetItem(size_t index) override;

	void DeleteItem(size_t index) override;

	size_t GetParagraphPosition(const IParagraph & paragraph) const override;
	size_t GetImagePosition(const IImage & paragraph) const override;

	void SetTitle(const string& title);

	string GetTitle() const;

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
	size_t GetItemPosition(const std::function<bool(const CConstDocumentItem&)>& pred) const;

private:
	vector<shared_ptr<CDocumentItem>> m_items;
	string m_title;
	ParagraphFactory m_paragraphFactory;
	ImageFactory m_imageFactory;
};

}
}
