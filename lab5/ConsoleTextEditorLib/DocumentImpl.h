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
	CDocumentImpl();

	CDocumentImpl(const CDocumentImpl&) = delete;

	void InsertParagraph(const std::shared_ptr<IParagraph>& paragraph,
		std::optional<size_t> position = std::optional<size_t>()) override;

	void InsertImage(std::shared_ptr<IImage> image, size_t position) override;

	size_t GetItemsCount()const override;

	CConstDocumentItem GetItem(size_t index)const override;
	CDocumentItem GetItem(size_t index) override;

	void DeleteItem(size_t index) override;

	void SetTitle(const std::string& title);

	std::string GetTitle() const;

private:
	template<typename OI>
	inline void InsertItem(std::optional<size_t> position, const std::shared_ptr<OI>& itemContent)
	{
		if (position && *position > m_items.size())
		{
			throw CInvalidPositionException();
		}
		const auto it = position ? next(m_items.cbegin(), *position) : m_items.cend();
		m_items.emplace(it, std::make_shared<CDocumentItem>(itemContent));
	}

	void CheckIndex(size_t index)const;
	size_t GetItemPosition(const std::function<bool(const CConstDocumentItem&)>& pred) const;

private:
	std::vector<std::shared_ptr<CDocumentItem>> m_items;
	std::string m_title;
};

}
}
