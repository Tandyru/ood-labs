#include "stdafx.h"
#include "InsertParagraphCommand.h"

namespace command
{

CInsertParagraphCommand::CInsertParagraphCommand(unique_ptr<input_command::InsertParagraphInputCommand>&& inputCommand, const document::IDocument & document)
	: CCommand(CommandType::InsertParagraph, document)
	, m_inputCommand(move(inputCommand))
{
}

void CInsertParagraphCommand::Accept()
{
	//optional<size_t> position = ;

	//document.InsertParagraph
}

void CInsertParagraphCommand::Unexecute()
{
}

}
