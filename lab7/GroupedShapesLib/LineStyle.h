#pragma once
#include "ILineStyle.h"

namespace shape
{

class CLineStyle : public ILineStyle
{
public:
	const size_t DEFAULT_LINE_THICKNESS = 1;

	void SetColor(const ColorType& color) override;
	ILineStyle::ColorType GetColor() const override;

	void SetThickness(const ILineStyle::ThicknessType& thickness) override;
	ILineStyle::ThicknessType GetThickness() const override;

private:
	ColorType m_color;
	ThicknessType m_thickness;
};

}