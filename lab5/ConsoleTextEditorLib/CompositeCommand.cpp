#include "stdafx.h"
#include "CompositeCommand.h"

namespace document
{
namespace command
{

CCompositeCommand::CCompositeCommand(impl::IDocumentImpl & document, Commands && commands)
	: m_document(document)
	, m_commands(move(commands))
{
}

void CCompositeCommand::Execute()
{
	for (auto& command : m_commands)
	{
		command->Execute();
	}
}

void CCompositeCommand::Unexecute()
{
	for (auto it = m_commands.rbegin(); it != m_commands.rend(); it++)
	{
		auto& command = *it;
		command->Unexecute();
	}
}

}
}
