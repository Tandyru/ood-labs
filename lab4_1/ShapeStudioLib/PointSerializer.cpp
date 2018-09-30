#include "stdafx.h"
#include "PointSerializer.h"
#include "json/json_writer.h"
#include "json/json_reader.h"

using namespace shape;

namespace shape_serializer
{
	PointSerializer::PointSerializer(const Point& point, const std::string& name)
		: m_name(name)
		, x(point.x)
		, y(point.y)
	{
	}

	std::string PointSerializer::Serialize(const Point& point)
	{
		PointSerializer serializer(point);

		return JSON::producer<PointSerializer>::convert(serializer);
	}

	Point PointSerializer::Unserialize(const std::string& json)
	{
		PointSerializer serializer = JSON::consumer<PointSerializer>::convert(json);

		return Point{ serializer.x, serializer.y };
	}

	void PointSerializer::serialize(JSON::Adapter& adapter)
	{
		JSON::Class root(adapter, !m_name.empty() ? m_name.c_str() : "Point");
		JSON_E(adapter, x);
		JSON_T(adapter, y);
	}

	shape::Point PointSerializer::GetPoint() const
	{
		return {x , y};
	}

}
