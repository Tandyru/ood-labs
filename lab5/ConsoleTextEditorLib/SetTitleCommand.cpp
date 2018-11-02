#include "stdafx.h"
#include "SetTitleCommand.h"
#include "ICommandVisitor.h"

namespace document
{
namespace command
{

CSetTitleCommand::CSetTitleCommand(impl::IDocumentImpl& document, const string& title)
	: m_document(document)
	, m_title(title)
{
}

void CSetTitleCommand::Execute()
{
	CCommand::Execute();
	m_oldTitle = m_document.GetTitle();
	m_document.SetTitle(m_title);
}

void CSetTitleCommand::Unexecute()
{
	CCommand::Unexecute();
	m_document.SetTitle(m_oldTitle);
}

string CSetTitleCommand::GetTitle() const
{
	return m_title;
}

}
}
