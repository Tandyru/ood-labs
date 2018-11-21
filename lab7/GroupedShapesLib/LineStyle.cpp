#include "stdafx.h"
#include "LineStyle.h"

namespace shape
{

void CLineStyle::SetColor(const ColorType& color)
{
	m_color = color;
}

CLineStyle::ColorType CLineStyle::GetColor() const
{
	return m_color;
}

void CLineStyle::SetLineThickness(const ILineStyle::ThicknessType& thickness)
{
	m_thickness = thickness;
}

ILineStyle::ThicknessType CLineStyle::GetLineThickness() const
{
	return m_thickness;
}

}
