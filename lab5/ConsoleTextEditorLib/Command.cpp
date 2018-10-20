#include "stdafx.h"
#include "Command.h"

namespace document
{
namespace command
{

CCommand::CCommand(CommandType type, document::impl::IDocumentImpl& document)
	: m_document(document)
{
}

}
}
