#include "stdafx.h"
#include "Paragraph.h"
#include "ReplaceTextCommand.h"

using namespace std;

namespace document
{

CParagraph::CParagraph(const string & text, 
	const shared_ptr<command::ICommandHistory>& commandHistory)
	: m_text(text)
	, m_commandHistory(commandHistory)
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
		auto command = make_unique<command::CReplaceTextCommand>(shared_from_this(), text);
		m_commandHistory->Do(move(command));
	}
	m_text = text;
}

}
