#pragma once
#include "../GroupedShapesLib/ICanvas.h"

class CCanvas : public shape::ICanvas
{
public: 
	CCanvas(Gdiplus::Graphics& graphics, unsigned width, unsigned height);

	// Inherited via ICanvas
	void SetOriginalSize(double width, double height) override;
	void DrawLine(shape::Point from, shape::Point to) override;
	void DrawEllipse(shape::Point leftTop, double width, double height) override;
	void FillEllipse(shape::Point leftTop, double width, double height) override;
	void FillShape(const std::vector<shape::Point>& points) override;
	void SetFillColor(const shape::Color& color) override;
	void SetDrawColor(const shape::Color& color) override;
	void SetLineThickness(double thickness) override;

private:
	double m_originalWidth = 0;
	double m_originalHeight = 0;
	Gdiplus::Graphics& m_graphics;
	unsigned m_width;
	unsigned m_height;
	Gdiplus::Pen m_pen;
	Gdiplus::SolidBrush m_brush;
};