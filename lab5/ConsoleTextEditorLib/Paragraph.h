#pragma once
#include "IParagraph.h"
#include "ICommandHistory.h"
#include "IParagraphCommandFactory.h"

namespace document
{

class CParagraph
	: public IParagraph
{
public:
	using BeforeTextChangeHandler = std::function<void(const IParagraph& paragraph, const string & newText)>;

	CParagraph(const string & text, const shared_ptr<command::ICommandHistory> & commandHistory, 
		const shared_ptr<command::IParagraphCommandFactory> & commandFactory);

	// IParagraph
	string GetText() const override;
	void SetText(const string & text) override;

private:
	string m_text;
	shared_ptr<command::ICommandHistory> m_commandHistory;
	shared_ptr<command::IParagraphCommandFactory> m_commandFactory;
};

}
