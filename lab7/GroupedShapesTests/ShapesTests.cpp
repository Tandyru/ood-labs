#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GroupedShapesLib/Triangle.h"

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
		CTriangle triangle;

		ShapesTests() 
			: triangle(triangleV1, triangleV2, triangleV3)
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
	};
}