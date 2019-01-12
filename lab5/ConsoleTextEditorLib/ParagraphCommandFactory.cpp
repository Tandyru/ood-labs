#include "stdafx.h"
#include "ParagraphCommandFactory.h"
#include "ReplaceTextCommand.h"

namespace document
{
namespace command
{

CParagraphCommandFactory::CParagraphCommandFactory(impl::IDocumentImpl& document)
	: m_document(document)
{
}

unique_ptr<CReplaceTextCommand> CParagraphCommandFactory::CreateReplaceTextCommand(const IParagraph & paragraph, const string & newText)
{
	auto position = m_document.GetParagraphPosition(paragraph);
	return make_unique<command::CReplaceTextCommand>(m_document, position, newText);
}

}
}

