#pragma once
#include "json/json_adapter.h"
#include "Ellipse.h"
#include "ColorSerializer.h"
#include "PointSerializer.h"

namespace shape_serializer
{

	class EllipseSerializer
	{
	public:
		static const char* STRING_ID;

		EllipseSerializer() = default;
		EllipseSerializer(const shape::CEllipse& Ellipse);

		static std::unique_ptr<shape::CShape> Create(const std::string& descr);

		static std::string Serialize(const shape::CEllipse& rect);

		static std::unique_ptr<shape::CEllipse> Unserialize(const std::string& json);

		void serialize(JSON::Adapter& adapter);

	private:
		ColorSerializer color;
		PointSerializer center;
		double horizontalRadius = 0;
		double verticalRadius = 0;
	};
}