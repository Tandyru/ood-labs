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
	using BeforeTextChangeHandler = std::function<void(const IParagraph& paragraph, const std::string & newText)>;

	CParagraph(const std::string & text, const std::shared_ptr<command::ICommandHistory> & commandHistory,
		const std::shared_ptr<command::IParagraphCommandFactory> & commandFactory);

	// IParagraph
	std::string GetText() const override;
	void SetText(const std::string & text) override;

private:
	std::string m_text;
	std::shared_ptr<command::ICommandHistory> m_commandHistory;
	std::shared_ptr<command::IParagraphCommandFactory> m_commandFactory;
};

}
