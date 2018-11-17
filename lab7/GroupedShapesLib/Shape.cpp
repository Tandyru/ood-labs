#include "stdafx.h"
#include "Shape.h"
#include "LineStyle.h"

namespace shape
{

CShape::CShape()
	: m_lineStyle(make_shared<CLineStyle>())
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
	return shared_ptr<IFillStyle>();
}

}