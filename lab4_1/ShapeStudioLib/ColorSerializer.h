#pragma once
#include "json/json_adapter.h"
#include "Color.h"

namespace shape_serializer
{

	class ColorSerializer
	{
	public:
		ColorSerializer() = default;
		ColorSerializer(Color color, const std::string& name = std::string());

		static std::string Serialize(Color color);
		static Color Unserialize(const std::string& json);

		void serialize(JSON::Adapter& adapter);

		Color GetColor() const;

	private:
		std::string m_name;
		static const std::pair<Color, const char*> m_map[];
		std::string color;
	};

}