#pragma once
#include "IFillStyle.h"

namespace shape
{

class CFillStyle : public IFillStyle
{
public:
	//CFillStyle() = default;
	CFillStyle(const Color& color, bool fill);

	// Inherited via IFillStyle
	void SetColor(const ColorType& color) override;
	ColorType GetColor() const override;
	void SetFill(const FillType& fill) override;
	IFillStyle::FillType GetFill() const override;

private:
	ColorType m_color;
	FillType m_fill;
};

}