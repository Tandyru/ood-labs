#include "stdafx.h"
#include "Paragraph.h"
#include "ReplaceTextCommand.h"

namespace document
{

CParagraph::CParagraph(const string & text, 
	const shared_ptr<command::ICommandHistory>& commandHistory,
	const shared_ptr<command::IParagraphCommandFactory> & commandFactory)
	: m_text(text)
	, m_commandHistory(commandHistory)
	, m_commandFactory(commandFactory)
{
}

string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(const string & text)
{
	if (m_commandHistory && m_commandHistory->ShouldCreateCommand())
	{
		auto command = m_commandFactory->CreateReplaceTextCommand(*this, text);
		m_commandHistory->Do(move(command));
	}
	m_text = text;
}

}
