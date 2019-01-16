#include "stdafx.h"
#include "Canvas.h"

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
}

void CCanvas::FillEllipse(shape::Point leftTop, double width, double height)
{
	//m_graphics.FillEllipse(m_brush)
}

void CCanvas::FillShape(const std::vector<shape::Point>& points)
{
}

void CCanvas::SetFillColor(shape::Color color)
{
}

void CCanvas::SetDrawColor(shape::Color color)
{
}

void CCanvas::SetLineThickness(double thickness)
{
}
