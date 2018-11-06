#include "stdafx.h"
#include "ReplaceTextCommand.h"

namespace document
{
namespace command
{

CReplaceTextCommand::CReplaceTextCommand(impl::IDocumentImpl& document, size_t position, const string& text)
	: m_document(document)
	, m_position(position)
	, m_text(text)
{
}

void CReplaceTextCommand::Execute()
{
	CCommand::Execute();
	auto item = m_document.GetItem(m_position);
	auto paragraph = item.GetParagraph();
	if (!paragraph)
	{
		throw runtime_error("The attempt to replace text of non-paragraph item.");
	}
	m_oldText = paragraph->GetText();
	paragraph->SetText(m_text);
}

void CReplaceTextCommand::Unexecute()
{
	CCommand::Unexecute();
	auto item = m_document.GetItem(m_position);
	auto paragraph = item.GetParagraph();
	if (!paragraph)
	{
		throw runtime_error("The attempt to replace text of non-paragraph item.");
	}
	paragraph->SetText(m_oldText);
}

size_t CReplaceTextCommand::GetPosition() const
{
	return m_position;
}

string CReplaceTextCommand::GetText() const
{
	return m_text;
}

}
}
