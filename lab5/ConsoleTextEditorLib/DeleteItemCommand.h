#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"

namespace document
{
namespace command
{

class CDeleteItemCommand : public CCommand
{
public:
	CDeleteItemCommand(impl::IDocumentImpl& document, size_t);

	void Execute() override;
	void Unexecute() override;

	void Accept(ICommandVisitor & visitor) const override;

	size_t GetPosition() const;
	shared_ptr<IParagraph> GetDeletedParagraph() const;
	shared_ptr<IImage> GetDeletedImage() const;

private:
	size_t m_position;
	shared_ptr<IParagraph> m_paragraph;
	shared_ptr<IImage> m_image;
};

}
}
