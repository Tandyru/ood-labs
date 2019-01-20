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

	//	���������� ������� ������ �����
	virtual void DrawLine(Point from, Point to) = 0;

	//	���������� ������
	virtual void DrawEllipse(Point leftTop, double width, double height) = 0;

	//	��������� ������
	virtual void FillEllipse(Point leftTop, double width, double height) = 0;

	//	��������� �������������, �������� �������� �����
	virtual void FillShape(const std::vector<Point>& points) = 0;

	//	�������� ���� ���������� ���������� �������� �����
	virtual void SetFillColor(const Color& color) = 0;

	//	�������� ���� ��������� �����
	virtual void SetDrawColor(const Color& color) = 0;

	//	�������� ������� ��������� �����
	virtual void SetLineThickness(double thickness) = 0;

	virtual ~ICanvas() = default;
};

}
