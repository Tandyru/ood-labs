#include "pch.h"
#include "shape_drawing_lib.h"
#include "modern_graphics_lib.h"

// Пространство имен приложения (доступно для модификации)
namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter & painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	CRectangle rectangle({ 30, 40 }, 18, 24);

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

class CanvasAdapter : public graphics_lib::ICanvas
{
	using CPoint = modern_graphics_lib::CPoint;
public:
	CanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer & renderer)
		: m_renderer(renderer)
		, m_lineBegin(0, 0)
	{
		m_renderer.BeginDraw();
	}

	~CanvasAdapter()
	{
		m_renderer.EndDraw();
	}

	void MoveTo(int x, int y) override
	{
		m_lineBegin = CPoint(x, y);
	}

	void LineTo(int x, int y) override
	{
		const CPoint lineEnd(x, y);
		m_renderer.DrawLine(m_lineBegin, lineEnd);
		m_lineBegin = lineEnd;
	}
private:
	modern_graphics_lib::CModernGraphicsRenderer & m_renderer;
	CPoint m_lineBegin;
};

void PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib::CModernGraphicsRenderer renderer(cout);

	CanvasAdapter adapter(renderer);
	shape_drawing_lib::CCanvasPainter painter(adapter);
	PaintPicture(painter);
}

}

int main()
{
	cout << "Should we use new API (y)?";
	string userInput;
	if (getline(cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		app::PaintPictureOnModernGraphicsRenderer();
	}
	else
	{
		app::PaintPictureOnCanvas();
	}

	return 0;
}
