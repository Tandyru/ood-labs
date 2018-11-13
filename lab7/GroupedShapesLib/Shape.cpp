#include "stdafx.h"
#include "Shape.h"

namespace shape
{



Rect CShape::GetFrame() const
{
	return Rect();
}

void CShape::SetFrame(Rect rect)
{
}

shared_ptr<IGroup> CShape::GetGroup()
{
	return shared_ptr<IGroup>();
}

shared_ptr<ILineStyle> CShape::GetLineStyle()
{
	return shared_ptr<ILineStyle>();
}

shared_ptr<IFillStyle> CShape::GetFillStyle()
{
	return shared_ptr<IFillStyle>();
}

}