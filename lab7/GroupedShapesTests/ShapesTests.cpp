#include "stdafx.h"
#include "CppUnitTest.h"
#include "ColorToWstring.h"
#include "ThicknessToWstring.h"
#include "../GroupedShapesLib/Triangle.h"
#include "../GroupedShapesLib/Rectangle.h"
#include "../GroupedShapesLib/Ellipse.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace shape;

namespace GroupedShapesTests
{		
	TEST_CLASS(ShapesTests)
	{
	public:
		const Point triangleV1 = {10, 10};
		const Point triangleV2 = { 25, 25 };
		const Point triangleV3 = { 8, 120 };
		const Point rectLeftTop = { 22, 15 };
		const Point rectRightBottom = { 112, 153 };
		const Point ellipseCenter = { 43, 51 };
		const double ellipseHorizontalRadius = 106;
		const double ellipseVerticalRadius = 49;
		CTriangle triangle;
		CRectangle rectangle;
		CEllipse ellipse;

		ShapesTests() 
			: triangle(triangleV1, triangleV2, triangleV3)
			, rectangle(rectLeftTop.x, rectLeftTop.y, rectRightBottom.x, rectRightBottom.y)
			, ellipse(ellipseCenter, ellipseHorizontalRadius, ellipseVerticalRadius)
		{
		}

		TEST_METHOD(TestGetGroupReturnsNull)
		{
			Assert::IsTrue(!triangle.GetGroup());
		}

		TEST_METHOD(TestTriangleFrame)
		{
			auto rect = triangle.GetFrame();
			Assert::AreEqual(rect.left, triangleV3.x);
			Assert::AreEqual(rect.top, triangleV1.y);
			Assert::AreEqual(rect.right, triangleV2.x);
			Assert::AreEqual(rect.bottom, triangleV3.y);
		}

		TEST_METHOD(TestTriangleSetFrame)
		{
			Rect newRect(55, 66, 77, 88);
			triangle.SetFrame(newRect);
			auto resultRect = triangle.GetFrame();
			Assert::AreEqual(newRect.left, resultRect.left);
			Assert::AreEqual(newRect.top, resultRect.top);
			Assert::AreEqual(newRect.right, resultRect.right);
			Assert::AreEqual(newRect.bottom, resultRect.bottom);
		}

		TEST_METHOD(TestRectangleFrame)
		{
			auto rect = rectangle.GetFrame();
			Assert::AreEqual(rect.left, rectLeftTop.x);
			Assert::AreEqual(rect.top, rectLeftTop.y);
			Assert::AreEqual(rect.right, rectRightBottom.x);
			Assert::AreEqual(rect.bottom, rectRightBottom.y);
		}

		TEST_METHOD(TestRectangleSetFrame)
		{
			Rect newRect(55, 66, 77, 88);
			rectangle.SetFrame(newRect);
			auto resultRect = rectangle.GetFrame();
			Assert::AreEqual(newRect.left, resultRect.left);
			Assert::AreEqual(newRect.top, resultRect.top);
			Assert::AreEqual(newRect.right, resultRect.right);
			Assert::AreEqual(newRect.bottom, resultRect.bottom);
		}

		TEST_METHOD(TestEllipseFrame)
		{
			auto rect = ellipse.GetFrame();
			Assert::AreEqual(rect.left, ellipseCenter.x - ellipseHorizontalRadius);
			Assert::AreEqual(rect.top, ellipseCenter.y - ellipseVerticalRadius);
			Assert::AreEqual(rect.right, ellipseCenter.x + ellipseHorizontalRadius);
			Assert::AreEqual(rect.bottom, ellipseCenter.y + ellipseVerticalRadius);
		}

		TEST_METHOD(TestEllipseSetFrame)
		{
			Rect newRect(55, 66, 77, 88);
			ellipse.SetFrame(newRect);
			auto resultRect = ellipse.GetFrame();
			Assert::AreEqual(newRect.left, resultRect.left);
			Assert::AreEqual(newRect.top, resultRect.top);
			Assert::AreEqual(newRect.right, resultRect.right);
			Assert::AreEqual(newRect.bottom, resultRect.bottom);
		}

		TEST_METHOD(TestLineStyle)
		{
			ILineStyle::ThicknessType expectedThickness = 2;
			Color expectedColor = { 127, 127, 127, 127 };
			auto shape = make_shared<CTriangle>(Point(), Point(), Point());
			auto lineStyle = shape->GetLineStyle();
			lineStyle->SetThickness(expectedThickness);
			lineStyle->SetColor(expectedColor);
			auto lineStyle2 = shape->GetLineStyle();
			shape.reset();
			Assert::AreEqual(expectedThickness, lineStyle2->GetThickness());
			Assert::AreEqual(expectedColor, *lineStyle2->GetColor());
		}


	};
}