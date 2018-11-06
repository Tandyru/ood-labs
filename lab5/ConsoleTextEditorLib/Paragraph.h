#pragma once
#include "IParagraph.h"

namespace document
{

class CParagraph
	: public IParagraph
{
public:
	using BeforeTextChangeHandler = std::function<void(const IParagraph& paragraph, const string & newText)>;

	CParagraph(const string & text);

	// IParagraph
	string GetText() const override;
	void SetText(const string & text) override;

	void SetOnBeforeTextChange(const BeforeTextChangeHandler& handler);
private:
	string m_text;
	BeforeTextChangeHandler m_onBeforeTextChange;
};

}
