#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ShapeStudioLib/RectanglePainter.h"
#include "../ShapeStudioLib/Rectangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace shape;
using namespace painter;

namespace ShapeStudioTests
{		
	TEST_CLASS(ShapePaintersTests)
	{
	public:
		class CanvasMock : public ICanvas
		{
		public:
			void SetColor(Color color) override
			{
				this->color = color;
			}

			void DrawLine(shape::Point from, shape::Point to) override
			{
				drawLineCount++;
			}

			void DrawEllipse(shape::Point leftTop, double width, double height) override
			{
				drawEllipseCount++;
			}

			Color color = Color::Black;
			unsigned int drawLineCount = 0;
			unsigned int drawEllipseCount = 0;
		};


		TEST_METHOD(TestRectanglePainter)
		{
			Color expectedColor = Color::Red;

			shape::CRectangle rectangle(expectedColor, { 10, 20 }, { 30, 40 });

			CanvasMock canvas;
			auto painter = painter::CreateRectanglePainter(rectangle);
			painter(canvas);

			Assert::IsTrue(canvas.color == expectedColor);
			Assert::IsTrue(canvas.drawLineCount == 4);
		}

	};
}