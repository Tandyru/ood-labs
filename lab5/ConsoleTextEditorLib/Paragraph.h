#pragma once
#include "IParagraph.h"
#include "ICommandHistory.h"

namespace document
{

class CParagraph
	: public IParagraph
	, public std::enable_shared_from_this<CParagraph>
{
public:
	using BeforeTextChangeHandler = std::function<void(const IParagraph& paragraph, const std::string & newText)>;

	CParagraph(const std::string & text, const std::shared_ptr<command::ICommandHistory> & commandHistory);

	// IParagraph
	std::string GetText() const override;
	void SetText(const std::string & text) override;

private:
	std::string m_text;
	std::shared_ptr<command::ICommandHistory> m_commandHistory;
};

}
