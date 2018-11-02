#pragma once
#include "IDocumentImpl.h"

namespace document
{
namespace command
{

class ICommandVisitor;

class CCommand
{
public:
	virtual ~CCommand() = default;

	virtual void Execute();
	virtual void Unexecute();

protected:
	bool m_executed = false;
};

}
}
