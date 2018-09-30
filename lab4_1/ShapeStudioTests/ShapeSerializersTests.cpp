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

//Logger::WriteMessage(json.c_str());

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

	};
}