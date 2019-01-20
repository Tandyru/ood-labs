#include "stdafx.h"
#include "Canvas.h"
#include <algorithm>

using namespace shape;
using namespace Gdiplus;

CCanvas::CCanvas(Gdiplus::Graphics & graphics, unsigned width, unsigned height)
	: m_graphics(graphics)
	, m_pen(Gdiplus::Color::Black)
	, m_brush(Gdiplus::Color::Gray)
	, m_width(width)
	, m_height(height)
{
}

void CCanvas::SetOriginalSize(double width, double height)
{
	m_originalWidth = width;
	m_originalHeight = height;
}

void CCanvas::DrawLine(shape::Point from, shape::Point to)
{
	m_graphics.DrawLine(&m_pen, REAL(from.x), REAL(from.y), REAL(to.x), REAL(to.y));
}

void CCanvas::DrawEllipse(shape::Point leftTop, double width, double height)
{
	m_graphics.DrawEllipse(&m_pen, REAL(leftTop.x), REAL(leftTop.y), REAL(width), REAL(height));
}

void CCanvas::FillEllipse(shape::Point leftTop, double width, double height)
{
	m_graphics.FillEllipse(&m_brush, REAL(leftTop.x), REAL(leftTop.y), REAL(width), REAL(height));
}

void CCanvas::FillShape(const std::vector<shape::Point>& points)
{
	std::vector<PointF> polygonPoints;
	std::transform(points.begin(), points.end(), back_inserter(polygonPoints), [](const shape::Point& point) -> PointF {
		return PointF(REAL(point.x), REAL(point.y));
	});
	m_graphics.FillPolygon(&m_brush, &polygonPoints[0], polygonPoints.size());
}

namespace {

inline Gdiplus::Color Convert(const shape::Color& color) {
	return Gdiplus::Color(color.a, color.r, color.g, color.b);
}

}

void CCanvas::SetFillColor(const shape::Color& color)
{
	m_brush.SetColor(Convert(color));
}

void CCanvas::SetDrawColor(const shape::Color& color)
{
	m_pen.SetColor(Convert(color));
}

void CCanvas::SetLineThickness(double thickness)
{
	m_pen.SetWidth(REAL(thickness));
}
