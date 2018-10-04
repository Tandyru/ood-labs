#include "stdafx.h"
#include "Canvas.h"

CCanvas::CCanvas(HDC hdc)
	: m_hdc(hdc)
{
}

CCanvas::~CCanvas()
{
	if (m_originalPen != NULL)
	{
		SelectObject(m_hdc, m_originalPen);
	}
}

void CCanvas::SetColor(Color color)
{
	/*
	HPEN hPen = CreatePen(PS_DASHDOT, 1, RGB(255, 0, 0));

	HGDIOBJ original = SelectObject(m_hdc, GetStockObject(DC_PEN));
	if (m_originalPen == NULL)
	{
		m_originalPen = original;
	}
	*/
	// TODO: 
}

void CCanvas::DrawLine(shape::Point from, shape::Point to)
{
	// TODO: 
}

void CCanvas::DrawEllipse(shape::Point leftTop, double width, double height)
{
	// TODO: 
}
