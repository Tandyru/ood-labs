#pragma once
#include "ICanvas.h"
#include <functional>

namespace painter
{
	using ShapePainter = std::function<void(ICanvas& canvas)>;
}
