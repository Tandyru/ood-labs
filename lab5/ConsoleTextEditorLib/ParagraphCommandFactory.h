#pragma once
#include "IParagraph.h"
#include "ReplaceTextCommand.h"
#include "IParagraphCommandFactory.h"
#include "IDocumentImpl.h"

namespace document
{
namespace command
{

class CParagraphCommandFactory : public IParagraphCommandFactory
{
public:
	CParagraphCommandFactory(impl::IDocumentImpl& document);

	std::unique_ptr<CReplaceTextCommand> CreateReplaceTextCommand(const IParagraph & paragraph, const std::string & newText) override;

private:
	impl::IDocumentImpl& m_document;
};

}
}
