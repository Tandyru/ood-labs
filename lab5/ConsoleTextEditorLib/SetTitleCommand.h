#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"

namespace document
{
namespace command
{

class CSetTitleCommand : public CCommand
{
public:
	CSetTitleCommand(impl::IDocumentImpl& document, const string& title);

	void Execute() override;
	void Unexecute() override;

	string GetTitle() const;

private:
	impl::IDocumentImpl& m_document;
	string m_oldTitle;
	string m_title;
};

}
}
