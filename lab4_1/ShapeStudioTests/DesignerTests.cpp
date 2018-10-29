#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ShapeStudioLib/Designer.h"
#include "../ShapeStudioLib/Rectangle.h"
#include "../ShapeStudioLib/Ellipse.h"
#include "../ShapeStudioLib/UnknownShapeTypeException.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ShapeStudioTests
{		
	TEST_CLASS(DesignerTests)
	{
		class ShapeFactoryMock : public IShapeFactory
		{
			std::unique_ptr<shape::CShape> CreateShape(const std::string& descr) const override
			{
				if (descr == "rectangle")
				{
					return make_unique<shape::CRectangle>(Color::Black, shape::Point{ 10, 20 }, shape::Point{ 30, 40 });
				}
				if (descr == "ellipse")
				{
					return make_unique<shape::CEllipse>(Color::Black, shape::Point{ 50, 60 }, 70, 80);
				}
				throw UnknownShapeTypeException(descr);
			}
		};
	public:
		TEST_METHOD(TestDraftCreation)
		{
			CDesigner designer(make_unique<ShapeFactoryMock>());

			const std::string input = "rectangle\nellipse";

			istringstream strm(input);

			auto draft = designer.CreateDraft(strm);

			Assert::IsTrue(bool(draft));
			Assert::IsTrue(draft->GetShapeCount() == 2);
			auto shape1 = draft->GetShape(0);
			auto shape2 = draft->GetShape(1);
			Assert::IsTrue(shape1->GetType() == shape::ShapeType::Rectangle);
			Assert::IsTrue(shape2->GetType() == shape::ShapeType::Ellipse);
		}

		TEST_METHOD(TestDraftCreationithInvalidInput)
		{
			CDesigner designer(make_unique<ShapeFactoryMock>());

			const std::string input = "unknown\n type";

			istringstream strm(input);

			try
			{
				auto draft = designer.CreateDraft(strm);
				Assert::Fail();
			}
			catch (UnknownShapeTypeException)
			{
			}
			catch (exception)
			{
				Assert::Fail();
			}
		}
	};
}