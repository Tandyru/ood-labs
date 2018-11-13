#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GroupedShapesLib/Group.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace shape;

namespace GroupedShapesTests
{		
	TEST_CLASS(ShapeGroupTests)
	{
	public:
		shared_ptr<CGroup> group;

		ShapeGroupTests()
			: group(make_shared<CGroup>())
		{
		}

		TEST_METHOD(TestGetGroupReturnsNonNull)
		{
			Assert::IsTrue(bool(group->GetGroup()));
		}
	};
}