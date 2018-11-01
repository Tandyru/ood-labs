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
	{
		// TODO: написать код конструктора
	}

	void Draw(graphics_lib::ICanvas & canvas)const override
	{
		// TODO: написать код рисования треугольника на холсте
	}
private:
	// TODO: дописать приватную часть
};

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point & leftTop, int width, int height)
	{
		m_leftTop = leftTop;
		m_width = width;
		m_height = height;
	}

	void Draw(graphics_lib::ICanvas & canvas)const override
	{
		const auto leftTop = m_leftTop;
		const auto rightBottom = Point{ leftTop.x + m_width, leftTop.y + m_height };
		const Point rightTop{ rightBottom.x, leftTop.y };
		const Point leftBottom{ leftTop.x, rightBottom.y };
		//canvas.DrawLine(leftTop, rightTop);
		//canvas.DrawLine(rightTop, rightBottom);
		//canvas.DrawLine(rightBottom, leftBottom);
		//canvas.DrawLine(leftBottom, leftTop);
		// TODO: написать код рисования прямоугольника на холсте
	}
private:
	Point m_leftTop; 
	int m_width;
	int m_height;
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
