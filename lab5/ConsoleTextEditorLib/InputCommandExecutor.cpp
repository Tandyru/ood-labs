#include "stdafx.h"
#include "InputCommandExecutor.h"

namespace input_command
{

CInputCommandExecutor::CInputCommandExecutor(shared_ptr<document::IDocument> document, ostream& out)
	: m_document(document)
	, m_out(out)
{
}

void input_command::CInputCommandExecutor::ExecuteCommand(unique_ptr<InputCommand>&& command)
{
	assert(command);
	auto commandType = command->type;
	switch (commandType)
	{
	}
}

}
