#pragma once
#include "IParagraph.h"

namespace document
{
namespace command
{

class CReplaceTextCommand;

class IParagraphCommandFactory
{
public:
	virtual std::unique_ptr<CReplaceTextCommand> CreateReplaceTextCommand(const IParagraph & paragraph, const std::string & newText) = 0;

	virtual ~IParagraphCommandFactory() = default;
};

}
}
