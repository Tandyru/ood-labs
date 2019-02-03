#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"
#include "IResource.h"
#include "IImage.h"

namespace document
{
namespace command
{

class CInsertImageCommand : public CCommand
{
public:
	CInsertImageCommand(impl::IDocumentImpl& document, std::optional<size_t> position, 
		std::shared_ptr<IImage> image);
private:
	void ExecuteImpl() override;
	void UnexecuteImpl() override;

	impl::IDocumentImpl& m_document;
	std::optional<size_t> m_position;
	size_t m_insertedPosition = 0;
	std::shared_ptr<IImage> m_image;
};

}
}
