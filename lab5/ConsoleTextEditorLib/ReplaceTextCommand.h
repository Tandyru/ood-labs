#pragma once
#include "Command.h"
#include "IParagraph.h"

namespace document
{
namespace command
{

class CReplaceTextCommand : public CCommand
{
public:
	CReplaceTextCommand(std::shared_ptr<IParagraph> paragraph, const std::string& text);

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	std::shared_ptr<IParagraph> m_paragraph;
	std::string m_text;
	std::string m_oldText;
};

}
}
