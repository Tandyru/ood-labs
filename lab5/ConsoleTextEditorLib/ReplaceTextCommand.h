#pragma once
#include "Command.h"
#include "ReplaceTextInputCommand.h"

namespace command
{

class CReplaceTextCommand : public CCommand
{
public:
	CReplaceTextCommand(unique_ptr<input_command::ReplaceTextInputCommand>&& inputCommand, const document::IDocument& document);

	void Accept() override;
	void Unexecute() override;

private:
	unique_ptr<input_command::ReplaceTextInputCommand> m_inputCommand;
};

}
