#include "stdafx.h"
#include "EllipseSerializer.h"
#include "PointSerializer.h"
#include "json/json_writer.h"
#include "json/json_reader.h"

using namespace std;
using namespace shape;

namespace shape_serializer
{
	const char* EllipseSerializer::STRING_ID = "Ellipse";

	EllipseSerializer::EllipseSerializer(const CEllipse& ellipse)
		: color(ellipse.GetColor(), "color")
		, center(ellipse.GetCenter(), "center")
		, horizontalRadius(ellipse.GetHorizontalRadius())
		, verticalRadius(ellipse.GetVerticalRadius())
	{
	}

	unique_ptr<CShape> EllipseSerializer::Create(const std::string& descr)
	{
		return Unserialize(descr);
	}

	std::string EllipseSerializer::Serialize(const CEllipse& Ellipse)
	{
		EllipseSerializer serializer(Ellipse);
		return JSON::producer<EllipseSerializer>::convert(serializer);
	}

	unique_ptr<CEllipse> EllipseSerializer::Unserialize(const std::string& json)
	{
		auto serializer = JSON::consumer<EllipseSerializer>::convert(json);
		auto color = serializer.color.GetColor();
		auto center = serializer.center.GetPoint();
		auto horizontalRadius = serializer.horizontalRadius;
		auto verticalRadius = serializer.verticalRadius;
		return make_unique<CEllipse>(color, center, horizontalRadius, verticalRadius);
	}

	void EllipseSerializer::serialize(JSON::Adapter& adapter)
	{
		JSON::Class root(adapter, STRING_ID);
		JSON_E(adapter, color);
		JSON_E(adapter, center);
		JSON_E(adapter, horizontalRadius);
		JSON_T(adapter, verticalRadius);
	}

}