#pragma once
#include "IParagraph.h"
#include "IImage.h"
#include "DocumentItem.h"

namespace document
{
namespace impl
{

class IDocumentImpl
{
public:
	virtual shared_ptr<IParagraph> InsertParagraph(const string& text,
		optional<size_t> position = optional<size_t>()) = 0;

	virtual shared_ptr<IImage> InsertImage(const Path& path, int width, int height,
		optional<size_t> position = optional<size_t>()) = 0;

	virtual size_t GetItemsCount()const = 0;

	virtual CConstDocumentItem GetItem(size_t index)const = 0;
	virtual CDocumentItem GetItem(size_t index) = 0;

	virtual void DeleteItem(size_t index) = 0;

	virtual void SetTitle(const string& title) = 0;
	virtual string GetTitle() const = 0;

	virtual ~IDocumentImpl() = default;
};

}
}
