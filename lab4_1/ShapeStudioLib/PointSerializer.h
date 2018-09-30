#pragma once
#include "json/json_adapter.h"
#include "Point.h"

namespace shape_serializer
{

	class PointSerializer
	{
	public:
		PointSerializer() = default;
		PointSerializer(const shape::Point& Point, const std::string& name = std::string());

		static std::string Serialize(const shape::Point& Point);
		static shape::Point Unserialize(const std::string& json);

		void serialize(JSON::Adapter& adapter);

		shape::Point GetPoint() const;
	private:
		std::string m_name;
		double x;
		double y;
	};

}