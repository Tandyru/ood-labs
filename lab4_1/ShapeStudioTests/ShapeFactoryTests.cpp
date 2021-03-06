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

		TEST_METHOD(TestCreateTriangle)
		{
			auto descr = R"({"Triangle":{"color":{"color":"yellow"},"vertex1":{"x":40,"y":10},"vertex2":{"x":10,"y":40},"vertex3":{"x":50,"y":40}}})";
			CShapeFactory factory;
			auto shape = factory.CreateShape(descr);

			Assert::IsTrue(bool(shape));
			if (shape)
			{
				Assert::IsTrue(shape->GetType() == shape::ShapeType::Triangle);
			}
		}

		TEST_METHOD(TestCreateEllipse)
		{
			auto descr = R"({"Ellipse":{"color":{"color":"blue"},"center":{"x":60,"y":60},"horizontalRadius":40,"verticalRadius":20}})";
			CShapeFactory factory;
			auto shape = factory.CreateShape(descr);

			Assert::IsTrue(bool(shape));
			if (shape)
			{
				Assert::IsTrue(shape->GetType() == shape::ShapeType::Ellipse);
			}
		}

		TEST_METHOD(TestCreateRegularPolygon)
		{
			auto descr = R"({"RegularPolygon":{"color":{"color":"black"},"vertexCount":5,"center":{"x":70,"y":70},"radius":40}})";
			CShapeFactory factory;
			auto shape = factory.CreateShape(descr);

			Assert::IsTrue(bool(shape));
			if (shape)
			{
				Assert::IsTrue(shape->GetType() == shape::ShapeType::RegularPolygon);
			}
		}

	};
}