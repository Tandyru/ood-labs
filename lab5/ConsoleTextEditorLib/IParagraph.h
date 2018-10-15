#pragma once

namespace document
{

/* �������� ������*/
class IParagraph
{
public:
	virtual string GetText()const = 0;
	virtual void SetText(const string& text) = 0;
	virtual ~IParagraph() = default;
};

}
