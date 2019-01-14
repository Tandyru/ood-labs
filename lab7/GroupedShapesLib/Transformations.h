#pragma once
#include "Point.h"
#include "Rect.h"

namespace shape
{
namespace transform
{

Point TransformVertexToNewRect(Point vertex, const Rect& oldRect, const Rect& newRect);

Rect TransformRect(Rect rect, const Rect& oldRect, const Rect& newRect);

}
}
