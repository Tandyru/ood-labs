#include "stdafx.h"
#include "Picture.h"
#include "../GroupedShapesLib/Group.h"
#include "../GroupedShapesLib/Rectangle.h"
#include "../GroupedShapesLib/Triangle.h"
#include "../GroupedShapesLib/Ellipse.h"

using namespace std;
using namespace shape;

namespace
{

void AppendShape(const shared_ptr<CGroup>& group, shared_ptr<CShape> shape)
{
	group->GetGroup()->InsertShapeAtIndex(shape, group->GetGroup()->GetShapeCount());
}

}

unique_ptr<CPicture> GetPicture()
{
	auto root = make_shared<CGroup>();

	auto sky = make_shared<CRectangle>(0, 0, 640, 480);
	sky->GetFillStyle()->SetColor(Color{180, 200, 255, 255});
	AppendShape(root, sky);

	auto sea = make_shared<CRectangle>(0, 120, 640, 480);
	sea->GetFillStyle()->SetColor(Color{ 25, 60, 120, 255 });
	AppendShape(root, sea);

	auto sun = make_shared<CEllipse>(Point{ 80, 60 }, 30, 30);
	sun->GetFillStyle()->SetColor(Color{ 240, 255, 30, 255 });
	AppendShape(root, sun);

	auto boat = make_shared<CGroup>();
	// ??

	return make_unique<CPicture>(root, 640, 480);
}
