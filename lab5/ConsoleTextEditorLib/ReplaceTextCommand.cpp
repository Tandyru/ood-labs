#include "stdafx.h"
#include "ReplaceTextCommand.h"

namespace document
{
namespace command
{

CReplaceTextCommand::CReplaceTextCommand(impl::IDocumentImpl& document, size_t position, const string& text)
	: CCommand(CommandType::ReplaceText, document)
	, m_position(position)
	, m_text(text)
{
}

void CReplaceTextCommand::Execute()
{
	CCommand::Execute();
	auto paragraph = GetParagraph();
	m_oldText = paragraph->GetText();
	paragraph->SetText(m_text);
}

void CReplaceTextCommand::Unexecute()
{
	CCommand::Unexecute();
	auto paragraph = GetParagraph();
	paragraph->SetText(m_oldText);
	m_oldText.erase();
}

shared_ptr<IParagraph> CReplaceTextCommand::GetParagraph()
{
	auto item = m_document.GetItem(m_position);
	auto paragraph = item.GetParagraph();
	if (!paragraph)
	{
		throw std::runtime_error("Invalid document replace text command");
	}
	return paragraph;
}

}
}
