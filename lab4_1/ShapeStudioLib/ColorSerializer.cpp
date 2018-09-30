#include "stdafx.h"
#include "ColorSerializer.h"
#include "MapEnum.h"
#include "json/json_writer.h"
#include "json/json_reader.h"

namespace shape_serializer
{
	const std::pair<Color, const char*> ColorSerializer::m_map[] = {
		{ Color::Green, "green" },
		{ Color::Red, "red" },
		{ Color::Blue, "blue" },
		{ Color::Yellow, "yellow" },
		{ Color::Pink, "pink" },
		{ Color::Black, "black" },
	};

	ColorSerializer::ColorSerializer(Color _color, const std::string& name)
		: m_name(name)
	{
		color = MapEnum(m_map, _color);
	}

	std::string ColorSerializer::Serialize(Color color)
	{
		ColorSerializer serializer(color);

		return JSON::producer<ColorSerializer>::convert(serializer);
	}

	Color ColorSerializer::Unserialize(const std::string& json)
	{
		ColorSerializer serializer = JSON::consumer<ColorSerializer>::convert(json);

		return ReverseStringMapEnum(m_map, serializer.color);
	}

	void ColorSerializer::serialize(JSON::Adapter& adapter)
	{
		JSON::Class root(adapter, !m_name.empty() ? m_name.c_str() : "Color");
		JSON_T(adapter, color);
	}

	Color ColorSerializer::GetColor() const
	{
		return ReverseStringMapEnum(m_map, color);
	}

}
