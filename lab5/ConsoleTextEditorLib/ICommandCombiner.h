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
	virtual unique_ptr<CCommand> Combine(const CCommand& prevCommand, const CCommand & nextCommand) const = 0;

	//virtual unique_ptr<CCommand> CombineWithPrevious(const CDeleteItemCommand& prevCommand, const CCommand & nextCommand) const = 0;
	//virtual unique_ptr<CCommand> Combine(const CDeleteItemCommand& prevCommand, const CInsertParagraphCommand & nextCommand) const = 0;
	//virtual unique_ptr<CCommand> Combine(const CDeleteItemCommand& prevCommand, const CInsertImageCommand & nextCommand) const = 0;

	virtual ~ICommandCombiner() = default;
};

}
}
