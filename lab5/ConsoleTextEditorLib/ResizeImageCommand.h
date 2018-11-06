#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"

namespace document
{
namespace command
{

class CResizeImageCommand : public CCommand
{
public:
	CResizeImageCommand(impl::IDocumentImpl& document, size_t position, unsigned int width, unsigned int height);

	void Execute() override;
	void Unexecute() override;

	size_t GetPosition() const;
	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

private:
	impl::IDocumentImpl& m_document;
	size_t m_position;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_oldWidth = 0;
	unsigned int m_oldHeight = 0;
};

}
}
