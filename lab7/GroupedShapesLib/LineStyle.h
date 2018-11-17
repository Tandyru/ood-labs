#pragma once
#include "ILineStyle.h"

namespace shape
{

class CLineStyle : public ILineStyle
{
public:
	const size_t DEFAULT_LINE_THICKNESS = 1;

	void SetColor(Color color) override;
	Color GetColor() const override;

	void SetLineThickness(ILineStyle::ThicknessType thickness) override;
	ILineStyle::ThicknessType GetLineThickness() const override;

private:
	Color m_color;
	size_t m_thickness = DEFAULT_LINE_THICKNESS;
};

}