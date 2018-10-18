#include "stdafx.h"
#include "ReplaceTextCommand.h"

namespace command
{

CReplaceTextCommand::CReplaceTextCommand(unique_ptr<input_command::ReplaceTextInputCommand>&& inputCommand, const document::IDocument & document)
	: CCommand(CommandType::ReplaceText, document)
	, m_inputCommand(move(inputCommand))
{
}

}
