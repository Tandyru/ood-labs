#include "stdafx.h"
#include "RegularPolygonSerializer.h"
#include "PointSerializer.h"
#include "json/json_writer.h"
#include "json/json_reader.h"

using namespace std;
using namespace shape;

namespace shape_serializer
{
	const char* RegularPolygonSerializer::STRING_ID = "RegularPolygon";

	RegularPolygonSerializer::RegularPolygonSerializer(const CRegularPolygon& RegularPolygon)
		: color(RegularPolygon.GetColor(), "color")
		, vertexCount(RegularPolygon.GetVertexCount())
		, center(RegularPolygon.GetCenter(), "center")
		, radius(RegularPolygon.GetRadius())
	{
	}

	unique_ptr<CShape> RegularPolygonSerializer::Create(const std::string& descr)
	{
		return Unserialize(descr);
	}

	std::string RegularPolygonSerializer::Serialize(const CRegularPolygon& RegularPolygon)
	{
		RegularPolygonSerializer serializer(RegularPolygon);
		return JSON::producer<RegularPolygonSerializer>::convert(serializer);
	}

	unique_ptr<CRegularPolygon> RegularPolygonSerializer::Unserialize(const std::string& json)
	{
		auto serializer = JSON::consumer<RegularPolygonSerializer>::convert(json);
		auto color = serializer.color.GetColor();
		auto vertexCount = serializer.vertexCount;
		auto center = serializer.center.GetPoint();
		auto radius = serializer.radius;
		return make_unique<CRegularPolygon>(color, vertexCount, center, radius);
	}

	void RegularPolygonSerializer::serialize(JSON::Adapter& adapter)
	{
		JSON::Class root(adapter, STRING_ID);
		JSON_E(adapter, color);
		JSON_E(adapter, vertexCount);
		JSON_E(adapter, center);
		JSON_T(adapter, radius);
	}

}