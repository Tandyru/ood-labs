#include "stdafx.h"
#include "CppUnitTest.h"
#include "ColorToWstring.h"
#include "ThicknessToWstring.h"
#include "../GroupedShapesLib/Group.h"
#include "../GroupedShapesLib/Triangle.h"
#include "../GroupedShapesLib/Rectangle.h"
#include "../GroupedShapesLib/Ellipse.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace shape;

namespace GroupedShapesTests
{		
	TEST_CLASS(ShapeGroupTests)
	{
	public:
		const Color color1;
		const Color color2;
		shared_ptr<CGroup> group;

		ShapeGroupTests()
			: color1({121, 1, 123, 124})
			, color2({2, 134, 135, 255})
		{
			group = make_shared<CGroup>();
		}

		TEST_METHOD(TestGetGroupReturnsNonNull)
		{
			Assert::IsTrue(bool(group->GetGroup()));
		}

		TEST_METHOD(TestInsertShapeIntoEnd)
		{
			auto shape = CreateShape();
			group->InsertShapeAtIndex(shape, 0);
			shape = CreateShape();
			group->InsertShapeAtIndex(shape, 1);
			Assert::AreEqual(size_t(2), group->GetShapeCount());
		}

		TEST_METHOD(TestInsertShapeIntoIncorrectPosition)
		{
			auto shape = CreateShape();
			bool exception = false;
			try
			{
				group->InsertShapeAtIndex(shape, 1);
			} 
			catch (...)
			{
				exception = true;
			}
			Assert::IsTrue(exception);
		}

		TEST_METHOD(TestGetShape)
		{
			auto shape = CreateShape();
			group->InsertShapeAtIndex(shape, 0);
			group->GetShapeAtIndex(0);
			Assert::IsTrue(true);
		}

		TEST_METHOD(TestGetShapeAtIncorrectIndex)
		{
			auto shape = CreateShape();
			group->InsertShapeAtIndex(shape, 0);
			bool exception = false;
			try
			{
				group->GetShapeAtIndex(1);
			}
			catch (...)
			{
				exception = true;
			}
			Assert::IsTrue(exception);
		}

		TEST_METHOD(TestRemoveShapeAtIndex)
		{
			auto shape = CreateShape();
			group->InsertShapeAtIndex(shape, 0);
			group->RemoveShapeAtIndex(0);
			Assert::AreEqual(size_t(0), group->GetShapeCount());
		}

		TEST_METHOD(TestGetGroupLineStyle)
		{
			auto shape = CreateShape();
			SetLineStyle1(shape->GetLineStyle());
			group->InsertShapeAtIndex(shape, 0);

			auto rectangle = CreateRectangle();
			SetLineStyle2(rectangle->GetLineStyle());
			group->InsertShapeAtIndex(rectangle, 0);

			auto ellipse = CreateEllipse();
			SetLineStyle2(ellipse->GetLineStyle());
			group->InsertShapeAtIndex(ellipse, 0);

			auto lineStyle = group->GetLineStyle();
			Assert::AreEqual(ILineStyle::ColorType(), lineStyle->GetColor());
			Assert::AreEqual(ILineStyle::ThicknessType(), lineStyle->GetLineThickness());
			// ??
		}

		shared_ptr<IShape> CreateShape() const
		{
			return make_shared<CTriangle>(Point(), Point(), Point());
		}

		shared_ptr<IShape> CreateRectangle() const
		{
			return make_shared<CRectangle>(0, 0, 100, 100);
		}

		shared_ptr<IShape> CreateEllipse() const
		{
			return make_shared<CEllipse>(Point(), 100, 50);
		}

		void SetLineStyle1(shared_ptr<ILineStyle> style)
		{
			style->SetColor(color1);
			style->SetLineThickness(1.2);
		}

		void SetLineStyle2(shared_ptr<ILineStyle> style)
		{
			style->SetColor(color2);
			style->SetLineThickness(2.2);
		}
	};
}