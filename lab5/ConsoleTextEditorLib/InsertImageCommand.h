#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"
#include "IResource.h"

namespace document
{
namespace command
{

class CInsertImageCommand : public CCommand
{
public:
	CInsertImageCommand(impl::IDocumentImpl& document, std::optional<size_t> position, 
		unsigned int width, unsigned int height, std::unique_ptr<resources::IResource>&& resource);
private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl& m_document;
	std::optional<size_t> m_position;
	size_t m_insertedPosition = 0;
	unsigned int m_width;
	unsigned int m_height;
	std::shared_ptr<resources::IResource> m_resource;
};

}
}
