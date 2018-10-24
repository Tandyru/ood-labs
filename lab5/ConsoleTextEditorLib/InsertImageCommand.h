#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"

namespace document
{
namespace command
{

class CInsertImageCommand : public CCommand
{
public:
	CInsertImageCommand(impl::IDocumentImpl& document, optional<size_t> position, unsigned int width, unsigned int height, string path);

	void Execute() override;
	void Unexecute() override;

	void Accept(ICommandVisitor & visitor) const override;

private:
	optional<size_t> m_position;
	unsigned int m_width;
	unsigned int m_height;
	string m_path;
};

}
}
