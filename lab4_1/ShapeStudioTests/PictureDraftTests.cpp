#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ShapeStudioLib/PictureDraft.h"
#include "../ShapeStudioLib/Rectangle.h"
#include "../ShapeStudioLib/Ellipse.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ShapeStudioTests
{		
	TEST_CLASS(PictureDraftTests)
	{
	public:
		
		TEST_METHOD(TestCreation)
		{
			vector<unique_ptr<shape::CShape>> shapes;
			shapes.push_back(make_unique<shape::CRectangle>(Color::Black, shape::Point{ 10, 20 }, shape::Point{ 30, 40 }));
			shapes.push_back(make_unique<shape::CEllipse>(Color::Black, shape::Point{ 50, 60 }, 70, 80));
			auto expectedSize = shapes.size();
			auto expectedType = shapes[1]->GetType();

			CPictureDraft draft(move(shapes));

			Assert::AreEqual(expectedSize, draft.GetShapeCount());
			Assert::IsTrue(expectedType == draft.GetShape(1)->GetType());
		}
	};
}