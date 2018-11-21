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

void ForEach(IGroup& group, const function<void(IShape&)>& func)
{
	auto count = group.GetShapeCount();
	for (decltype(count) index = 0; index < count; index++)
	{
		auto shape = group.GetShapeAtIndex(index);
		func(*shape);
	}
};

void ForEach(weak_ptr<IGroup> group, const function<void(IShape&)>& func)
{
	WithGroup<IGroup>(group, [&](IGroup& group) {
		ForEach(group, func);
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

void CGroupLineStyle::SetLineThickness(const ILineStyle::ThicknessType & thickness)
{
	ForEach(m_group, [&](IShape& shape) {
		shape.GetLineStyle()->SetLineThickness(thickness);
	});
}

}

