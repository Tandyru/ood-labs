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

	void Execute() override;
	void Unexecute() override;

private:
	optional<size_t> m_position;
	string m_text;
};

}
}
