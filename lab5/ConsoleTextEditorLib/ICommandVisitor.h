#pragma once
#include "DeleteItemCommand.h"
#include "InsertParagraphCommand.h"
#include "InsertImageCommand.h"

namespace document
{
namespace command
{

class ICommandVisitor
{
public:
	virtual void Visit(const CDeleteItemCommand& command) = 0;
	virtual void Visit(const CInsertParagraphCommand& command) = 0;
	virtual void Visit(const CInsertImageCommand& command) = 0;

	virtual ~ICommandVisitor() = default;
};

}
}
