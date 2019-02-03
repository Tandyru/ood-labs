#pragma once
#include "IParagraph.h"
#include "IImage.h"
#include "DocumentItem.h"
#include "IResource.h"

namespace document
{
namespace impl
{

class IDocumentImpl
{
public:

	virtual void InsertParagraph(const std::shared_ptr<IParagraph>& paragraph,
		std::optional<size_t> position = std::optional<size_t>()) = 0;

	virtual void InsertImage(std::shared_ptr<IImage> image, size_t position) = 0;

	virtual size_t GetItemsCount()const = 0;

	virtual CConstDocumentItem GetItem(size_t index)const = 0;
	virtual CDocumentItem GetItem(size_t index) = 0;

	virtual void DeleteItem(size_t index) = 0;

	virtual void SetTitle(const std::string& title) = 0;
	virtual std::string GetTitle() const = 0;

	virtual ~IDocumentImpl() = default;
};

}
}
