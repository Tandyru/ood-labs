#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ShapeStudioLib/Shapes.h"
#include "../ShapeStudioLib/ShapeSerializers.h"
#include "../ShapeStudioLib/json/json_writer.h"
#include <locale>
#include <codecvt>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace shape;
using namespace shape_serializer;

namespace ShapeStudioTests
{		
	TEST_CLASS(ShapeSerializersTests)
	{
	public:

		TEST_METHOD(TestReadColor)
		{
			Color expectedColor = Color::Red;

			auto json = ColorSerializer::Serialize(expectedColor);
//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//std::wstring wstr = converter.from_bytes(json);
//Assert::Fail(wstr.c_str(), LINE_INFO());
			auto color = ColorSerializer::Unserialize(json);

			Assert::IsTrue(expectedColor == color);
		}

		TEST_METHOD(TestReadPoint)
		{
			Point expectedPoint{11, 12};

			auto json = PointSerializer::Serialize(expectedPoint);
			auto point = PointSerializer::Unserialize(json);

			Assert::IsTrue(expectedPoint == point);
		}

		TEST_METHOD(TestReadRectangle)
		{
			shape::CRectangle expectedRectangle(Color::Red, { 11, 12 }, {13, 14});

			auto json = RectangleSerializer::Serialize(expectedRectangle);

			auto rectangle = RectangleSerializer::Unserialize(json);

			Assert::IsTrue(bool(rectangle));
			Assert::IsTrue(expectedRectangle == *rectangle);
		}

		TEST_METHOD(TestReadRectangleFromInvalidDescr)
		{
			try
			{
				auto rectangle = RectangleSerializer::Unserialize("Invalid descr");
				Assert::Fail();
			}
			catch (std::exception)
			{
			}
		}

		TEST_METHOD(TestReadTriangle)
		{
			shape::CTriangle expectedTriangle(Color::Yellow, { 11, 12 }, { 13, 14 }, { 15, 16 });

			auto json = TriangleSerializer::Serialize(expectedTriangle);

			auto triangle = TriangleSerializer::Unserialize(json);

			Assert::IsTrue(bool(triangle));
			Assert::IsTrue(expectedTriangle == *triangle);
		}

		TEST_METHOD(TestReadEllipse)
		{
			shape::CEllipse expectedEllipse(Color::Blue, { 60, 60 }, 40, 20);

			auto json = EllipseSerializer::Serialize(expectedEllipse);

//Logger::WriteMessage(json.c_str());

			auto ellipse = EllipseSerializer::Unserialize(json);

			Assert::IsTrue(bool(ellipse));
			Assert::IsTrue(expectedEllipse == *ellipse);
		}

		TEST_METHOD(TestReadRegularPolygon)
		{
			shape::CRegularPolygon expectedPolygon(Color::Black, 5, { 70, 70 }, 40);

			auto json = RegularPolygonSerializer::Serialize(expectedPolygon);

//Logger::WriteMessage(json.c_str());

			auto polygon = RegularPolygonSerializer::Unserialize(json);

			Assert::IsTrue(bool(polygon));
			Assert::IsTrue(expectedPolygon == *polygon);
		}
	};
}