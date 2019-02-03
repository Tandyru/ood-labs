#pragma once
#include "IDocument.h"
#include "InputCommand.h"
#include "IInputCommandVisitor.h"
#include "IDocument.h"
#include <ostream>

namespace input_command
{

class CInputCommandExecutor : public IInputCommandExecutor
{
public:
	using HelpCommandHandler = std::function<void(std::ostream& out)>;
	CInputCommandExecutor(document::IDocument& document, std::ostream& out,
		const HelpCommandHandler& helpHandler);
	CInputCommandExecutor(const CInputCommandExecutor&) = delete;
	
	// IInputCommandExecutor
	void ExecuteCommand(InputCommandType type) override;
	void ExecuteCommand(const InsertParagraphInputCommand& command) override;
	void ExecuteCommand(const InsertImageInputCommand& command) override;
	void ExecuteCommand(const SetTitleInputCommand& command) override;
	void ExecuteCommand(const ReplaceTextInputCommand& command) override;
	void ExecuteCommand(const ResizeImageInputCommand& command) override;
	void ExecuteCommand(const DeleteItemInputCommand& command) override;
	void ExecuteCommand(const SaveInputCommand& command) override;

private:
	document::IDocument & m_document;
	std::ostream& m_out;
	HelpCommandHandler m_helpHandler;
};

}
