#include "stdafx.h"
#include "GroupLineStyle.h"
#include "IGroup.h"
#include <functional>
#include "GroupUtils.h"

using namespace shape::group;

namespace shape
{

shape::CGroupLineStyle::CGroupLineStyle(weak_ptr<IGroup> group)
	: m_group(group)
{
}

void CGroupLineStyle::SetColor(const ColorType & color)
{
	ForEach(m_group, [&](IShape& shape) {
		shape.GetLineStyle()->SetColor(color);
	});
}

ILineStyle::ColorType CGroupLineStyle::GetColor() const
{
	return GetGroupCommonValue<ILineStyle::ColorType>(m_group, [&](IShape& shape) {
		return shape.GetLineStyle()->GetColor();
	});
}

void CGroupLineStyle::SetThickness(const ILineStyle::ThicknessType & thickness)
{
	ForEach(m_group, [&](IShape& shape) {
		shape.GetLineStyle()->SetThickness(thickness);
	});
}

ILineStyle::ThicknessType CGroupLineStyle::GetThickness() const
{
	return GetGroupCommonValue<ILineStyle::ThicknessType>(m_group, [&](IShape& shape) {
		return shape.GetLineStyle()->GetThickness();
	});
}

}

