#pragma once
#include "CommandType.h"
#include "IDocumentImpl.h"

namespace document
{
namespace command
{

class CCommand
{
public:
	CCommand(CommandType type, document::impl::IDocumentImpl& document);
	virtual ~CCommand() = default;

	virtual void Execute() = 0;
	virtual void Unexecute() = 0;

protected:
	CommandType m_type;
	document::impl::IDocumentImpl& m_document;
};

}
}
