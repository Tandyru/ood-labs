#include "stdafx.h"
#include "Command.h"

namespace document
{
namespace command
{

CCommand::CCommand(CommandType type, document::impl::IDocumentImpl& document)
	: m_document(document)
{
}

void CCommand::Execute()
{
	if (m_executed)
	{
		throw std::runtime_error("Trying to execute the command again");
	}
	m_executed = true;
}

void CCommand::Unexecute()
{
	if (!m_executed)
	{
		throw std::runtime_error("Trying to unexecute nonexecuted command");
	}
	m_executed = false;
}

void CCommand::Accept(ICommandVisitor & visitor) const
{
}

impl::IDocumentImpl & CCommand::GetDocument() const
{
	return m_document;
}


}
}
