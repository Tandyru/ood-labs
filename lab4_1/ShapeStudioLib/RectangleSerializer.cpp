#include "stdafx.h"
#include "RectangleSerializer.h"
#include "PointSerializer.h"
#include "json/json_writer.h"
#include "json/json_reader.h"

using namespace std;
using namespace shape;

namespace shape_serializer
{
	const char* RectangleSerializer::STRING_ID = "Rectangle";

	RectangleSerializer::RectangleSerializer()
	{
	}

	RectangleSerializer::RectangleSerializer(const CRectangle& rectangle)
		: color(rectangle.GetColor(), "color")
		, leftTop(rectangle.GetLeftTop(), "leftTop")
		, rightBottom(rectangle.GetRightBottom(), "rightBottom")
	{
	}

	unique_ptr<CShape> RectangleSerializer::Create(const std::string& descr)
	{
		return Unserialize(descr);
	}

	std::string RectangleSerializer::Serialize(const CRectangle& rectangle)
	{
		RectangleSerializer serializer(rectangle);
		return JSON::producer<RectangleSerializer>::convert(serializer);
	}

	unique_ptr<CRectangle> RectangleSerializer::Unserialize(const std::string& json)
	{
		auto serializer = JSON::consumer<RectangleSerializer>::convert(json);
		auto color = serializer.color.GetColor();
		auto leftTop = serializer.leftTop.GetPoint();
		auto rightBottom = serializer.rightBottom.GetPoint();
		return make_unique<CRectangle>(color, leftTop, rightBottom);
	}

	void RectangleSerializer::serialize(JSON::Adapter& adapter)
	{
		JSON::Class root(adapter, STRING_ID);
		JSON_E(adapter, color);
		JSON_E(adapter, leftTop);
		JSON_T(adapter, rightBottom);
	}

}