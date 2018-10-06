#include "stdafx.h"
#include "Canvas.h"
#include "../ShapeStudioLib/MapEnum.h"
#include <utility>
#include <cassert>

namespace
{
	COLORREF ConvertColor(Color color)
	{
		static std::pair<Color, COLORREF> map[] = {
			{ Green, RGB(0, 255, 0) },
			{ Red, RGB(255, 0, 0) },
			{ Blue, RGB(0, 0, 255) },
			{ Yellow, RGB(255, 255, 0) },
			{ Pink, RGB(255, 127, 127) },
			{ Black, RGB(0, 0, 0) },
		};
		return MapEnum(map, color);
	}
}

CCanvas::CCanvas(HDC hdc, unsigned int width, unsigned int height)
	: m_hdc(hdc)
	, m_width(width)
	, m_height(height)
	, m_scale(double(height) / 100.0)
{
	auto brash = GetStockObject(HOLLOW_BRUSH);
	m_originalBrush = SelectObject(m_hdc, brash);
}

CCanvas::~CCanvas()
{
	if (m_currentPen != NULL)
	{
		DeleteObject(m_currentPen);
	}
	if (m_originalPen != NULL)
	{
		SelectObject(m_hdc, m_originalPen);
	}
	if (m_originalBrush != NULL)
	{
		SelectObject(m_hdc, m_originalBrush);
	}
}

void CCanvas::SetColor(Color color)
{
	if (m_currentPen != NULL)
	{
		DeleteObject(m_currentPen);
	}
	m_currentPen = CreatePen(PS_SOLID, 2, ConvertColor(color));

	HGDIOBJ original = SelectObject(m_hdc, m_currentPen);
	if (m_originalPen == NULL)
	{
		m_originalPen = original;
	}
}

int CCanvas::CalcCoord(double coordinate)
{
	return int(coordinate * m_scale);
}

void CCanvas::DrawLine(shape::Point from, shape::Point to)
{
	assert(m_hdc != NULL);
	MoveToEx(m_hdc, CalcCoord(from.x), CalcCoord(from.y), NULL);
	LineTo(m_hdc, CalcCoord(to.x), CalcCoord(to.y));
}

void CCanvas::DrawEllipse(shape::Point leftTop, double width, double height)
{
	assert(m_hdc != NULL);
	Ellipse(m_hdc, CalcCoord(leftTop.x), CalcCoord(leftTop.y), CalcCoord(leftTop.x + width), CalcCoord(leftTop.y + height));
}
