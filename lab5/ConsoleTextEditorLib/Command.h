#pragma once
#include "CommandType.h"
#include "IDocument.h"

namespace command
{

class CCommand
{
public:
	CCommand(CommandType type, const document::IDocument& document);
	virtual ~CCommand() = default;

	virtual void Execute() = 0;
	virtual void Unexecute() = 0;

protected:
	CommandType m_type;
	const document::IDocument& document;
};

}