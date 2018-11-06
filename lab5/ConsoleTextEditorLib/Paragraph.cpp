#include "stdafx.h"
#include "Paragraph.h"

namespace document
{

CParagraph::CParagraph(const string & text)
	: m_text(text)
{
}

string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(const string & text)
{
	if (m_onBeforeTextChange)
	{
		m_onBeforeTextChange(*this, text);
	}
	m_text = text;
}

void CParagraph::SetOnBeforeTextChange(const BeforeTextChangeHandler & handler)
{
	m_onBeforeTextChange = handler;
}

}
