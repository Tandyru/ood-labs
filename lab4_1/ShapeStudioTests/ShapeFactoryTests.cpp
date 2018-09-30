#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ShapeStudioLib/ShapeFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ShapeStudioTests
{		
	TEST_CLASS(ShapeFactoryTests)
	{
	public:
		
		TEST_METHOD(TestCreateRectangle)
		{
			auto descr = R"({"Rectangle":{"color":{"color":"red"}, "leftTop" : {"x":11, "y" : 22}, "rightBottom" : {"x":33, "y" : 44}}})";
			CShapeFactory factory;
			auto shape = factory.CreateShape(descr);

			Assert::IsTrue(bool(shape));
			if (shape)
			{
				Assert::IsTrue(shape->GetType() == shape::ShapeType::Rectangle);
			}
		}

		TEST_METHOD(TestInvalidDescription)
		{
			auto descr = R"({inv"Rectangle":{")";
			CShapeFactory factory;
			try
			{
				auto shape = factory.CreateShape(descr);
				Assert::Fail();
			}
			catch (std::exception)
			{
			}
		}

		TEST_METHOD(TestUnknownTypeDescription)
		{
			auto descr = R"({"Unknown":{")";
			CShapeFactory factory;
			try
			{
				auto shape = factory.CreateShape(descr);
				Assert::Fail();
			}
			catch (std::exception)
			{
			}
		}

	};
}