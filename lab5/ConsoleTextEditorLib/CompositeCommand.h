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
	impl::IDocumentImpl & m_document;
	Commands m_commands;
};

}
}
