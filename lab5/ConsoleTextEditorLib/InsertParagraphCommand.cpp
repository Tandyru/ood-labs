#include "stdafx.h"
#include "InsertParagraphCommand.h"

namespace document
{
namespace command
{

CInsertParagraphCommand::CInsertParagraphCommand(impl::IDocumentImpl& document, optional<size_t> position, const string& text)
	: CCommand(CommandType::InsertParagraph, document)
	, m_position(position)
	, m_text(text)
{
}

void CInsertParagraphCommand::Execute()
{
	m_document.InsertParagraph(m_text, m_position);
}

void CInsertParagraphCommand::Unexecute()
{
}

}
}
