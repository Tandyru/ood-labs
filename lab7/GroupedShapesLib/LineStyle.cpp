#include "stdafx.h"
#include "LineStyle.h"

namespace shape
{

void CLineStyle::SetColor(Color color)
{
	m_color = color;
}

Color CLineStyle::GetColor() const
{
	return m_color;
}

void CLineStyle::SetLineThickness(ILineStyle::ThicknessType thickness)
{
	m_thickness = thickness;
}

ILineStyle::ThicknessType CLineStyle::GetLineThickness() const
{
	return m_thickness;
}

}
