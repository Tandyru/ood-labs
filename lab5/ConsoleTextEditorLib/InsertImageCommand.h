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
	CInsertImageCommand(impl::IDocumentImpl& document, optional<size_t> position, 
		unsigned int width, unsigned int height, unique_ptr<resources::IResource>&& resource);

	void Execute() override;
	void Unexecute() override;

	optional<size_t> GetPosition() const;
	Path GetPath() const;
	shared_ptr<resources::IResource> GetResource() const;

private:
	impl::IDocumentImpl& m_document;
	optional<size_t> m_position;
	size_t m_insertedPosition = 0;
	unsigned int m_width;
	unsigned int m_height;
	shared_ptr<resources::IResource> m_resource;
};

}
}
