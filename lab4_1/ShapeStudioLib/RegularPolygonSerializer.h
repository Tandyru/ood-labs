#pragma once
#include "json/json_adapter.h"
#include "RegularPolygon.h"
#include "ColorSerializer.h"
#include "PointSerializer.h"

namespace shape_serializer
{

	class RegularPolygonSerializer
	{
	public:
		static const char* STRING_ID;

		RegularPolygonSerializer() = default;
		RegularPolygonSerializer(const shape::CRegularPolygon& RegularPolygon);

		static std::unique_ptr<shape::CShape> Create(const std::string& descr);

		static std::string Serialize(const shape::CRegularPolygon& rect);

		static std::unique_ptr<shape::CRegularPolygon> Unserialize(const std::string& json);

		void serialize(JSON::Adapter& adapter);

	private:
		ColorSerializer color;
		unsigned int vertexCount = 0;
		PointSerializer center;
		double radius = 0;
	};
}