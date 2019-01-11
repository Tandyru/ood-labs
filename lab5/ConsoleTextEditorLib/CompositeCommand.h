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

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl & m_document;
	Commands m_commands;
};

}
}
