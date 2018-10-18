#pragma once
#include "Command.h"
#include "InsertParagraphInputCommand.h"

namespace command
{

class CInsertParagraphCommand : public CCommand
{
public:
	CInsertParagraphCommand(unique_ptr<input_command::InsertParagraphInputCommand>&& inputCommand, const document::IDocument& document);

	void Accept() override;
	void Unexecute() override;

private:
	const unique_ptr<input_command::InsertParagraphInputCommand> m_inputCommand;
};

}
