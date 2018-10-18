#pragma once
#include "IDocumentCommandFactory.h"

namespace command
{

class CDocumentCommandFactory : public IDocumentCommandFactory
{
public:
	CDocumentCommandFactory();

	// Inherited via IDocumentCommandFactory
	virtual unique_ptr<CCommand> CreateDocumentCommand() const override;
};

}
