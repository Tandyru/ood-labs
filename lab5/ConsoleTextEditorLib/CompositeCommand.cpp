#include "stdafx.h"
#include "CompositeCommand.h"

namespace document
{
namespace command
{

CCompositeCommand::CCompositeCommand(impl::IDocumentImpl & document, Commands && commands)
	: CCommand(CommandType::Composite, document)
	, m_commands(move(commands))
{
}

void CCompositeCommand::Execute()
{
	/*
	for (auto& command : m_commands)
	{
		command->Execute();
	}
	*/
}

void CCompositeCommand::Unexecute()
{
	/*
	for (auto it = m_commands.rbegin(); it != m_commands.rend(); it++)
	{
		auto& command = *it;
		command->Unexecute();
	}
	*/
}

}
}
