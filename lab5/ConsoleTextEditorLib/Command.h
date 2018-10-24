#pragma once
#include "CommandType.h"
#include "IDocumentImpl.h"

namespace document
{
namespace command
{

class ICommandVisitor;

class CCommand
{
public:
	CCommand(CommandType type, impl::IDocumentImpl& document);
	virtual ~CCommand() = default;

	virtual void Execute();
	virtual void Unexecute();

	virtual void Accept(ICommandVisitor & visitor) const;

	impl::IDocumentImpl& GetDocument() const;

protected:
	CommandType m_type;
	document::impl::IDocumentImpl& m_document;
	bool m_executed = false;
};

}
}
