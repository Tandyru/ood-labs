#include "stdafx.h"
#include "GroupFillStyle.h"
#include "IGroup.h"
#include "GroupUtils.h"

using namespace shape::group;

namespace shape
{

CGroupFillStyle::CGroupFillStyle(weak_ptr<IGroup> group)
	: m_group(group)
{
}

void CGroupFillStyle::SetColor(const ColorType & color)
{
	ForEach(m_group, [&](IShape& shape) {
		shape.GetFillStyle()->SetColor(color);
	});
}

IFillStyle::ColorType CGroupFillStyle::GetColor() const
{
	return GetGroupCommonValue<IFillStyle::ColorType>(m_group, [&](IShape& shape) {
		return shape.GetFillStyle()->GetColor();
	});
}

void CGroupFillStyle::SetFill(const FillType & fill)
{
	ForEach(m_group, [&](IShape& shape) {
		shape.GetFillStyle()->SetFill(fill);
	});
}

IFillStyle::FillType CGroupFillStyle::GetFill() const
{
	return GetGroupCommonValue<IFillStyle::FillType>(m_group, [&](IShape& shape) {
		return shape.GetFillStyle()->GetFill();
	});
}

}

