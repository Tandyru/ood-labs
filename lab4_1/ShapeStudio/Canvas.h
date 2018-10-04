#pragma once
#include "../ShapeStudioLib/ICanvas.h"

class CCanvas : public ICanvas
{
public:
	CCanvas(HDC hdc);
	~CCanvas();

	void SetColor(Color color) override;
	void DrawLine(shape::Point from, shape::Point to) override;
	void DrawEllipse(shape::Point leftTop, double width, double height) override;

private:
	HDC m_hdc;
	HGDIOBJ m_originalPen = NULL;
};

