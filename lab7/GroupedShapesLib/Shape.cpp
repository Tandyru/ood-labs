#include "stdafx.h"
#include "Shape.h"
#include "LineStyle.h"
#include "FillStyle.h"

namespace shape
{

CShape::CShape()
	: m_lineStyle(make_shared<CLineStyle>())
	, m_fillStyle(make_shared<CFillStyle>(Color{ 127, 127, 127, 255 }, true))
{
}

Rect CShape::GetFrame() const
{
	return Rect();
}

void CShape::SetFrame(Rect rect)
{
}

shared_ptr<IGroup> CShape::GetGroup()
{
	return shared_ptr<IGroup>();
}

shared_ptr<ILineStyle> CShape::GetLineStyle()
{
	return m_lineStyle;
}

shared_ptr<IFillStyle> CShape::GetFillStyle()
{
	return m_fillStyle;
}

}