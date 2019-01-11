#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"

namespace document
{
namespace command
{

class CInsertParagraphCommand : public CCommand
{
public:
	CInsertParagraphCommand(impl::IDocumentImpl& document, optional<size_t> position, const string& text);

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl& m_document;
	optional<size_t> m_position;
	size_t m_insertedPosition = 0;
	string m_text;
};

}
}
