#pragma once
#include "../ShapeStudioLib/ICanvas.h"

class CCanvas : public ICanvas
{
public:
	CCanvas(HDC hdc, unsigned int width, unsigned int height);
	~CCanvas();

	void SetColor(Color color) override;
	void DrawLine(shape::Point from, shape::Point to) override;
	void DrawEllipse(shape::Point leftTop, double width, double height) override;

private:
	inline int CalcCoord(double coordinate);

private:
	HDC m_hdc;
	const unsigned int m_width; 
	const unsigned int m_height;
	HGDIOBJ m_originalPen = NULL;
	HGDIOBJ m_originalBrush = NULL;
	HPEN m_currentPen = NULL;
	const double m_scale;
};

