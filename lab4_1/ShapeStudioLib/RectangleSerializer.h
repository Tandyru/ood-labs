#pragma once
#include "json/json_adapter.h"
#include "Rectangle.h"
#include "ColorSerializer.h"
#include "PointSerializer.h"

namespace shape_serializer
{

	class RectangleSerializer
	{
	public:
		static const char* STRING_ID;

		RectangleSerializer();
		RectangleSerializer(const shape::CRectangle& Rectangle);

		static std::unique_ptr<shape::CShape> Create(const std::string& descr);

		static std::string Serialize(const shape::CRectangle& rect);

		static std::unique_ptr<shape::CRectangle> Unserialize(const std::string& json);

		void serialize(JSON::Adapter& adapter);

	private:
		ColorSerializer color;
		PointSerializer leftTop;
		PointSerializer rightBottom;
	};

}