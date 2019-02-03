#include "stdafx.h"
#include "ReplaceTextCommand.h"
#include "IDocumentImpl.h"

using namespace std;

namespace document
{
namespace command
{

CReplaceTextCommand::CReplaceTextCommand(std::shared_ptr<IParagraph> paragraph, const string& text)
	: m_paragraph(paragraph)
	, m_text(text)
{
}

void CReplaceTextCommand::ExecuteImpl()
{
	m_oldText = m_paragraph->GetText();
	m_paragraph->SetText(m_text);
}

void CReplaceTextCommand::UnexecuteImpl()
{
	m_paragraph->SetText(m_oldText);
}

}
}
