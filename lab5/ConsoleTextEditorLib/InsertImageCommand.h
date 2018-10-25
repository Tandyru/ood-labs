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
	CInsertImageCommand(impl::IDocumentImpl& document, optional<size_t> position, unsigned int width, unsigned int height, Path path);

	void Execute() override;
	void Unexecute() override;

	void Accept(ICommandVisitor & visitor) const override;

	size_t GetInsertedPosition() const;

private:
	optional<size_t> m_position;
	size_t m_insertedPosition = 0;
	unsigned int m_width;
	unsigned int m_height;
	Path m_path;
};

}
}
