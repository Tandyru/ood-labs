#include "stdafx.h"
#include "SetTitleCommand.h"

namespace document
{
namespace command
{

CSetTitleCommand::CSetTitleCommand(impl::IDocumentImpl& document, const string& title)
	: m_document(document)
	, m_title(title)
{
}

void CSetTitleCommand::ExecuteImpl()
{
	m_oldTitle = m_document.GetTitle();
	m_document.SetTitle(m_title);
}

void CSetTitleCommand::UnexecuteImpl()
{
	m_document.SetTitle(m_oldTitle);
}

}
}
