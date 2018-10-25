#pragma once
#include "Command.h"
#include <vector>

namespace document
{
namespace command
{

class CCompositeCommand : public CCommand
{
public:
	using Commands = vector<unique_ptr<CCommand>>;
	CCompositeCommand(impl::IDocumentImpl & document, Commands && commands);

	void Execute() override;
	void Unexecute() override;

private:
	Commands m_commands;
};

}
}
