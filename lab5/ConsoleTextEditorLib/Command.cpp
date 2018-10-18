#include "stdafx.h"
#include "Command.h"

namespace command
{

using namespace document;

CCommand::CCommand(CommandType type, const IDocument & document)
	: m_document(document)
{
}

}
