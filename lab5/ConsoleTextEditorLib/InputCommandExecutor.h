#pragma once
#include "IDocument.h"
#include "InputCommand.h"
#include "IInputCommandExecutor.h"
#include <ostream>

namespace input_command
{

class CInputCommandExecutor : public IInputCommandExecutor
{
public:
	using HelpCommandHandler = function<void(ostream& out)>;
	CInputCommandExecutor(shared_ptr<document::IDocument> document, ostream& out, 
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
	void ShowHelp();

private:
	shared_ptr<document::IDocument> m_document;
	ostream& m_out;
	HelpCommandHandler m_helpHandler;
};

}
