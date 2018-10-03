#pragma once
#include "json/json_adapter.h"
#include "Triangle.h"
#include "ColorSerializer.h"
#include "PointSerializer.h"

namespace shape_serializer
{

	class TriangleSerializer
	{
	public:
		static const char* STRING_ID;

		TriangleSerializer() = default;
		TriangleSerializer(const shape::CTriangle& Triangle);

		static std::unique_ptr<shape::CShape> Create(const std::string& descr);

		static std::string Serialize(const shape::CTriangle& rect);

		static std::unique_ptr<shape::CTriangle> Unserialize(const std::string& json);

		void serialize(JSON::Adapter& adapter);

	private:
		ColorSerializer color;
		PointSerializer vertex1;
		PointSerializer vertex2;
		PointSerializer vertex3;
	};

}