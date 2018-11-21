#pragma once
#include "ILineStyle.h"

namespace shape
{

class CLineStyle : public ILineStyle
{
public:
	const size_t DEFAULT_LINE_THICKNESS = 1;

	void SetColor(const ColorType& color) override;
	ColorType GetColor() const override;

	void SetLineThickness(const ILineStyle::ThicknessType& thickness) override;
	ILineStyle::ThicknessType GetLineThickness() const override;

private:
	ColorType m_color;
	ThicknessType m_thickness;
};

}