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

void AppendShape(const shared_ptr<CGroup>& group, shared_ptr<IShape> shape)
{
	group->GetGroup()->InsertShapeAtIndex(shape, group->GetGroup()->GetShapeCount());
}

}

unique_ptr<CPicture> GetPicture()
{
	const auto pictureWidth = 640;
	const auto pictureHeight = 480;

	auto root = make_shared<CGroup>();

	auto sky = make_shared<CRectangle>(0, 0, pictureWidth, pictureHeight);
	sky->GetFillStyle()->SetColor(Color{180, 200, 255, 255});
	AppendShape(root, sky);

	auto horizontLine = 360;
	auto sea = make_shared<CRectangle>(0, horizontLine, pictureWidth, pictureHeight);
	sea->GetFillStyle()->SetColor(Color{ 25, 60, 120, 255 });
	AppendShape(root, sea);

	auto sun = make_shared<CEllipse>(Point{ 80, 60 }, 30, 30);
	sun->GetFillStyle()->SetColor(Color{ 240, 255, 30, 255 });
	sun->GetLineStyle()->SetColor(Color{ 240, 180, 30, 255 });
	AppendShape(root, sun);
	
	// Boat
	auto boat = make_shared<CGroup>();
	{
		const auto boatHCenter = pictureWidth / 2;
		const auto vCenter = horizontLine;
		const auto boatLength = 360;
		const auto baseLength = 160;
		const auto baseHeight = 80;
		const double baseLeft = boatHCenter - baseLength / 2;
		const double baseRight = boatHCenter + baseLength / 2;
		const double baseTop = horizontLine - baseHeight / 2;
		const double baseBottom = horizontLine + baseHeight / 2;
		auto hull = make_shared<CGroup>();
		auto hullBase = make_shared<CRectangle>(baseLeft, baseTop, baseRight, baseBottom);
		AppendShape(hull, hullBase);
		Point baseLeftTop = { baseLeft, baseTop };
		Point baseLeftBottom = { baseLeft, baseBottom };
		Point sternPoint = { boatHCenter - boatLength / 2, baseTop - 10 };
		auto stern = make_shared<CTriangle>(sternPoint, baseLeftTop, baseLeftBottom);
		AppendShape(hull, stern);
		Point baseRightTop = { baseRight, baseTop };
		Point baseRightBottom = { baseRight, baseBottom };
		Point bowPoint = { boatHCenter + boatLength / 2, sternPoint.y };
		auto bow = make_shared<CTriangle>(bowPoint, baseRightBottom, baseRightTop);
		AppendShape(hull, bow);
		hull->GetFillStyle()->SetColor(Color{ 200, 100, 0, 255 });
		AppendShape(boat, hull);
		// ??
	}
	AppendShape(root, boat);

	return make_unique<CPicture>(root, pictureWidth, pictureHeight);
}
