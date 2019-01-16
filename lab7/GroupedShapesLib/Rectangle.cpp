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

void CRectangle::DrawImpl(ICanvas & canvas)
{
	Point leftTop = Point{ m_rectangle.left, m_rectangle.top };
	Point rightTop = Point{ m_rectangle.right, m_rectangle.top };
	Point rightBottom = Point{ m_rectangle.right, m_rectangle.bottom };
	Point leftBottom = Point{ m_rectangle.left, m_rectangle.bottom };
	canvas.DrawLine(leftTop, rightTop);
	canvas.DrawLine(rightTop, rightBottom);
	canvas.DrawLine(rightBottom, leftBottom);
	canvas.DrawLine(leftBottom, leftTop);
	canvas.FillShape(std::vector<Point>{leftTop, rightTop, rightBottom, leftBottom});
}

}
