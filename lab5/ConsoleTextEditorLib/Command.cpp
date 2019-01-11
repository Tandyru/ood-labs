#include "stdafx.h"
#include "Command.h"

namespace document
{
namespace command
{

void CCommand::Execute()
{
	if (m_executed)
	{
		throw std::runtime_error("Trying to execute the command again");
	}
	m_executed = true;
	ExecuteImpl();
}

void CCommand::Unexecute()
{
	if (!m_executed)
	{
		throw std::runtime_error("Trying to unexecute nonexecuted command");
	}
	m_executed = false;
	UnexecuteImpl();
}

}
}
