#pragma once
#include "IDocument.h"
#include "InputCommand.h"
#include <ostream>

namespace input_command
{

class CInputCommandExecutor
{
public:
	CInputCommandExecutor(shared_ptr<document::IDocument> document, ostream& out);
	CInputCommandExecutor(const CInputCommandExecutor&) = delete;

	void ExecuteCommand(unique_ptr<InputCommand>&& command);

private:
	shared_ptr<document::IDocument> m_document;
	ostream& m_out;
};

}
