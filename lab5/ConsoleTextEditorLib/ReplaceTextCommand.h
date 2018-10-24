#pragma once
#include "Command.h"

namespace document
{
namespace command
{

class CReplaceTextCommand : public CCommand
{
public:
	CReplaceTextCommand(impl::IDocumentImpl& document, size_t position, const string& text);

	void Execute() override;
	void Unexecute() override;

private:
	shared_ptr<IParagraph> GetParagraph();

private:
	size_t m_position;
	string m_text;
	string m_oldText;
};

}
}
