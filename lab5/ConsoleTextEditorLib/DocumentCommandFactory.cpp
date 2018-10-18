#include "stdafx.h"
#include "DocumentCommandFactory.h"

namespace command
{

CDocumentCommandFactory::CDocumentCommandFactory()
{
}

unique_ptr<CCommand> CDocumentCommandFactory::CreateDocumentCommand() const
{
	return unique_ptr<CCommand>();
}

}
