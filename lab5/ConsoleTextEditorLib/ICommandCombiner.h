#pragma once
#include "Command.h"
#include "DeleteItemCommand.h"
#include "InsertParagraphCommand.h"
#include "InsertImageCommand.h"

namespace document
{
namespace command
{

class ICommandCombiner
{
public:
	virtual bool ShouldCombine(const CCommand& prevCommand, const CCommand & nextCommand) const = 0;

	virtual ~ICommandCombiner() = default;
};

}
}
