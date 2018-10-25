#pragma once
#include "Command.h"
#include "DocumentItemPosition.h"

namespace document
{
namespace command
{

class CInsertParagraphCommand : public CCommand
{
public:
	CInsertParagraphCommand(impl::IDocumentImpl& document, optional<size_t> position, const string& text);

	void Execute() override;
	void Unexecute() override;

	void Accept(ICommandVisitor & visitor) const override;

	//size_t GetInsertedPosition() const;
	optional<size_t> GetPosition() const;
	string GetText() const;

private:
	optional<size_t> m_position;
	size_t m_insertedPosition = 0;
	string m_text;
};

}
}
