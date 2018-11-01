#pragma once
#include "graphics_lib.h"

// Пространство имен библиотеки для рисования фигур (использует graphics_lib)
// Код библиотеки недоступен для изменения
namespace shape_drawing_lib
{
struct Point
{
	int x;
	int y;
};

// Интерфейс объектов, которые могут быть нарисованы на холсте из graphics_lib
class ICanvasDrawable
{
public:
	virtual void Draw(graphics_lib::ICanvas & canvas)const = 0;
	virtual ~ICanvasDrawable() = default;
};

class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(const Point & p1, const Point & p2, const Point & p3)
		: vertex1(p1)
		, vertex2(p2)
		, vertex3(p3)
	{
	}

	void Draw(graphics_lib::ICanvas & canvas)const override
	{
		canvas.MoveTo(vertex1.x, vertex1.y);
		canvas.LineTo(vertex2.x, vertex2.y);
		canvas.LineTo(vertex3.x, vertex3.y);
		canvas.LineTo(vertex1.x, vertex1.y);
	}
private:
	const Point vertex1;
	const Point vertex2;
	const Point vertex3;
};

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point & leftTop, int width, int height)
		: m_leftTop(leftTop)
		, m_width(width)
		, m_height(height)
	{
	}

	void Draw(graphics_lib::ICanvas & canvas)const override
	{
		const auto leftTop = m_leftTop;
		const auto rightBottom = Point{ leftTop.x + m_width, leftTop.y + m_height };
		const Point rightTop{ rightBottom.x, leftTop.y };
		const Point leftBottom{ leftTop.x, rightBottom.y };
		canvas.MoveTo(leftTop.x, leftTop.y);
		canvas.LineTo(rightTop.x, rightTop.y);
		canvas.LineTo(rightBottom.x, rightBottom.y);
		canvas.LineTo(leftBottom.x, leftBottom.y);
		canvas.LineTo(leftTop.x, leftTop.y);
	}
private:
	const Point m_leftTop; 
	const int m_width;
	const int m_height;
};

// Художник, способный рисовать ICanvasDrawable-объекты на ICanvas
class CCanvasPainter
{
public:
	CCanvasPainter(graphics_lib::ICanvas & canvas)
		: m_canvas(canvas)
	{
	}
	void Draw(const ICanvasDrawable & drawable)
	{
		drawable.Draw(m_canvas);
	}
private:
	graphics_lib::ICanvas & m_canvas;
};
}
