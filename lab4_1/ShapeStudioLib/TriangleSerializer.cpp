#include "stdafx.h"
#include "TriangleSerializer.h"
#include "PointSerializer.h"
#include "json/json_writer.h"
#include "json/json_reader.h"

using namespace std;
using namespace shape;

namespace shape_serializer
{
	const char* TriangleSerializer::STRING_ID = "Triangle";

	TriangleSerializer::TriangleSerializer(const CTriangle& Triangle)
		: color(Triangle.GetColor(), "color")
		, vertex1(Triangle.GetVertex1(), "vertex1")
		, vertex2(Triangle.GetVertex2(), "vertex2")
		, vertex3(Triangle.GetVertex3(), "vertex3")
	{
	}

	unique_ptr<CShape> TriangleSerializer::Create(const std::string& descr)
	{
		return Unserialize(descr);
	}

	std::string TriangleSerializer::Serialize(const CTriangle& triangle)
	{
		TriangleSerializer serializer(triangle);
		return JSON::producer<TriangleSerializer>::convert(serializer);
	}

	unique_ptr<CTriangle> TriangleSerializer::Unserialize(const std::string& json)
	{
		auto serializer = JSON::consumer<TriangleSerializer>::convert(json);
		auto color = serializer.color.GetColor();
		auto vertex1 = serializer.vertex1.GetPoint();
		auto vertex2 = serializer.vertex2.GetPoint();
		auto vertex3 = serializer.vertex3.GetPoint();
		return make_unique<CTriangle>(color, vertex1, vertex2, vertex3);
	}

	void TriangleSerializer::serialize(JSON::Adapter& adapter)
	{
		JSON::Class root(adapter, STRING_ID);
		JSON_E(adapter, color);
		JSON_E(adapter, vertex1);
		JSON_E(adapter, vertex2);
		JSON_T(adapter, vertex3);
	}

}