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

private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl& m_document;
	size_t m_position;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_oldWidth = 0;
	unsigned int m_oldHeight = 0;
};

}
}
