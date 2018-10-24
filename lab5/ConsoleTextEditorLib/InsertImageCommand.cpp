#include "stdafx.h"
#include "InsertImageCommand.h"
#include "ICommandVisitor.h"

namespace document
{
namespace command
{

void CInsertImageCommand::Accept(ICommandVisitor & visitor) const
{
	visitor.Visit(*this);
}

}
}
