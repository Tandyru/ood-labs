#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"
#include "IParagraph.h"
#include "IImage.h"

namespace document
{
namespace command
{

class CDeleteItemCommand : public CCommand
{
public:
	CDeleteItemCommand(impl::IDocumentImpl& document, size_t position);

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl& m_document;
	size_t m_position;
	std::shared_ptr<IParagraph> m_paragraph;
	std::shared_ptr<IImage> m_image;
	bool m_lastItemDeleted = false;
};

}
}
