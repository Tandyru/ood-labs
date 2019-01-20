#pragma once
#include "Color.h"
#include "Point.h"
#include <vector>

namespace shape
{

constexpr double NO_LINE_THICKNESS_VALUE = 0.0;

struct ICanvas
{
	virtual void SetOriginalSize(double width, double height) = 0;

	//	Нарисовать отрезок прямой линии
	virtual void DrawLine(Point from, Point to) = 0;

	//	Нарисовать эллипс
	virtual void DrawEllipse(Point leftTop, double width, double height) = 0;

	//	Заполнить эллипс
	virtual void FillEllipse(Point leftTop, double width, double height) = 0;

	//	Заполнить многоугольник, заданный массивом точек
	virtual void FillShape(const std::vector<Point>& points) = 0;

	//	Изменить цвет заполнения внутренних областей фигур
	virtual void SetFillColor(const Color& color) = 0;

	//	Изменить цвет рисования линий
	virtual void SetDrawColor(const Color& color) = 0;

	//	Изменить толщину рисования линий
	virtual void SetLineThickness(double thickness) = 0;

	virtual ~ICanvas() = default;
};

}
