#pragma once
#include "IParagraph.h"

namespace document
{

class CParagraph
	: public IParagraph
{
public:
	CParagraph(const string & text);

	// IParagraph
	string GetText() const override;
	void SetText(const string & text) override;
private:
	string m_text;
};

}
