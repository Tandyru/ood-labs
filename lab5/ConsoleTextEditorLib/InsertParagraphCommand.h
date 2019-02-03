#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"
#include "IParagraph.h"

namespace document
{
namespace command
{

class CInsertParagraphCommand : public CCommand
{
public:
	CInsertParagraphCommand(impl::IDocumentImpl& document, std::optional<size_t> position, std::shared_ptr<IParagraph> paragraph);

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl& m_document;
	std::optional<size_t> m_position;
	size_t m_insertedPosition = 0;
	std::shared_ptr<IParagraph> m_paragraph;
};

}
}
