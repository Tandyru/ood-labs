#include "stdafx.h"
#include "GroupLineStyle.h"
#include "IGroup.h"
#include <functional>

namespace shape
{

namespace
{

template<class T>
void WithGroup(weak_ptr<T> weakPtr, const function<void(T&)>& func)
{
	if (auto strong = weakPtr.lock())
	{
		func(*strong);
	}
}

void CancelableForEach(IGroup& group, const function<bool(IShape&)>& func)
{
	auto count = group.GetShapeCount();
	for (decltype(count) index = 0; index < count; index++)
	{
		auto shape = group.GetShapeAtIndex(index);
		if (!func(*shape))
		{
			break;
		}
	}
};

void ForEach(weak_ptr<IGroup> group, const function<void(IShape&)>& func)
{
	WithGroup<IGroup>(group, [&](IGroup& group) {
		CancelableForEach(group, [&](IShape& shape) {
			func(shape);
			return true;
		});
	});
}

void CancelableForEach(weak_ptr<IGroup> group, const function<bool(IShape&)>& func)
{
	WithGroup<IGroup>(group, [&](IGroup& group) {
		CancelableForEach(group, func);
	});
}

}

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
	ILineStyle::ColorType groupLineColor;
	bool first = true;
	ForEach(m_group, [&](IShape& shape) -> bool {
		auto color = shape.GetLineStyle()->GetColor();
		if (first)
		{
			first = false;
			groupLineColor = color;
		}
		else
		{
			if (groupLineColor != color) {
				groupLineColor.reset();
				return false;
			}
		}
		return true;
	});
	return groupLineColor;
}

void CGroupLineStyle::SetThickness(const ILineStyle::ThicknessType & thickness)
{
	ForEach(m_group, [&](IShape& shape) {
		shape.GetLineStyle()->SetThickness(thickness);
	});
}

ILineStyle::ThicknessType CGroupLineStyle::GetThickness() const
{
	ILineStyle::ThicknessType groupLineThickness;
	bool first = true;
	ForEach(m_group, [&](IShape& shape) -> bool {
		auto thickness = shape.GetLineStyle()->GetThickness();
		if (first)
		{
			first = false;
			groupLineThickness = thickness;
		}
		else
		{
			if (groupLineThickness != thickness) {
				groupLineThickness.reset();
				return false;
			}
		}
		return true;
	});
	return groupLineThickness;
}

}

