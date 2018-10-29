#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ShapeStudioLib/Shapes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace shape;

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
			rectangle.Draw(canvas);

			Assert::IsTrue(canvas.color == expectedColor);
			Assert::IsTrue(canvas.drawLineCount == 4);
		}

		TEST_METHOD(TestTrianglePainter)
		{
			Color expectedColor = Color::Green;

			shape::CTriangle rectangle(expectedColor, { 10, 20 }, { 30, 40 }, { 50, 60 });

			CanvasMock canvas;
			rectangle.Draw(canvas);

			Assert::IsTrue(canvas.color == expectedColor);
			Assert::IsTrue(canvas.drawLineCount == 3);
		}

		TEST_METHOD(TestEllipsePainter)
		{
			Color expectedColor = Color::Black;

			shape::CEllipse ellipse(expectedColor, { 10, 20 }, 30, 40);

			CanvasMock canvas;
			ellipse.Draw(canvas);

			Assert::IsTrue(canvas.color == expectedColor);
			Assert::IsTrue(canvas.drawLineCount == 0);
			Assert::IsTrue(canvas.drawEllipseCount == 1);
		}

		TEST_METHOD(TestRegularPolygonPainter)
		{
			Color expectedColor = Color::Pink;
			auto expectedVertexCount = 5;

			shape::CRegularPolygon polygon(expectedColor, expectedVertexCount, { 10, 20 }, 30);

			CanvasMock canvas;
			polygon.Draw(canvas);

			Assert::IsTrue(canvas.color == expectedColor);
			Assert::IsTrue(canvas.drawLineCount == expectedVertexCount);
			Assert::IsTrue(canvas.drawEllipseCount == 0);
		}
	};
}