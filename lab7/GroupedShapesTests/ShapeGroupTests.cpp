#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GroupedShapesLib/Group.h"
#include "../GroupedShapesLib/Triangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace shape;

namespace GroupedShapesTests
{		
	TEST_CLASS(ShapeGroupTests)
	{
	public:
		shared_ptr<CGroup> group;

		ShapeGroupTests()
		{
			group = make_shared<CGroup>();
		}

		TEST_METHOD(TestGetGroupReturnsNonNull)
		{
			Assert::IsTrue(bool(group->GetGroup()));
		}

		TEST_METHOD(TestInsertShape)
		{
			auto shape = CreateShape();
			group->InsertShapeAtIndex(shape, 0);
			Assert::AreEqual(size_t(1), group->GetShapeCount());
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

//		size_t GetShapeCount() const override;
//		shared_ptr<IShape> GetShapeAtIndex(size_t index) const override;
//		void InsertShapeAtIndex(shared_ptr<IShape> shape, size_t index) override;
//		void RemoveShapeAtIndex(size_t index) override;

		shared_ptr<IShape> CreateShape() const
		{
			return make_shared<CTriangle>(Point(), Point(), Point());
		}
	};
}