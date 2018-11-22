#pragma once
#include "IFillStyle.h"

namespace shape
{

class CFillStyle : public IFillStyle
{
public:
	//const Color DEFAULT_COLOR = Color{ 0, 0, 0, 255 };

	//CFillStyle();
	CFillStyle(const Color& color, bool fill);

	// Inherited via IFillStyle
	void SetColor(const Color& color) override;
	Color GetColor() const override;
	void SetFill(bool fill) override;
	bool GetFill() const override;

private:
	Color m_color;
	bool m_fill;
};

}