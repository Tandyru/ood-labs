#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ShapeStudioLib/PictureDraft.h"

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
			shapes.push_back(make_unique<shape::CShape>(Color::Green, shape::ShapeType::Rectangle));
			shapes.push_back(make_unique<shape::CShape>(Color::Red, shape::ShapeType::Ellipse));
			auto expectedSize = shapes.size();
			auto expectedType = shapes[1]->GetType();

			CPictureDraft draft(move(shapes));

			Assert::AreEqual(expectedSize, draft.GetShapeCount());
			Assert::IsTrue(expectedType == draft.GetShape(1)->GetType());
		}
	};
}