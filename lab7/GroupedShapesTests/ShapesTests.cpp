#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GroupedShapesLib/Triangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace shape;

namespace ConsoleTextEditorTests
{		
	TEST_CLASS(ShapesTests)
	{
	public:
		CTriangle triangle;

		ShapesTests() 
			: triangle({ 10, 10 }, {25, 25}, {8, 120})
		{
		}

		TEST_METHOD(TestGetGroupReturnsNull)
		{
			Assert::IsTrue(!triangle.GetGroup());
		}
	};
}