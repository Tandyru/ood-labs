#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"

namespace document
{
namespace command
{

class CDeleteItemCommand : public CCommand
{
public:
	CDeleteItemCommand(impl::IDocumentImpl& document, size_t);

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl& m_document;
	size_t m_position;
	shared_ptr<IParagraph> m_paragraph;
	shared_ptr<IImage> m_image;
	bool m_lastItemDeleted = false;
};

}
}
