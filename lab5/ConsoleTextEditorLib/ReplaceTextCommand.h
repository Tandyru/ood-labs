#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"

namespace document
{
namespace command
{

class CReplaceTextCommand : public CCommand
{
public:
	CReplaceTextCommand(impl::IDocumentImpl& document, size_t position, const string& text);

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl& m_document;
	size_t m_position;
	string m_text;
	string m_oldText;
};

}
}
