#include "stdafx.h"
#include "Rectangle.h"

namespace shape
{

CRectangle::CRectangle(double left, double top, double right, double bottom)
	: m_rectangle(left, top, right, bottom)
{
}

Rect CRectangle::GetFrame() const
{
	return m_rectangle;
}

void CRectangle::SetFrame(Rect rect)
{
	m_rectangle = rect;
}

void CRectangle::Draw(ICanvas & canvas) const
{
}

}
