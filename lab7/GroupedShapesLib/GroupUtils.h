#pragma once
#include <functional>

namespace shape
{
namespace group
{

template<class T>
void WithGroup(weak_ptr<T> weakPtr, const function<void(T&)>& func)
{
	if (auto strong = weakPtr.lock())
	{
		func(*strong);
	}
}

inline void CancelableForEach(IGroup& group, const function<bool(IShape&)>& func)
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

inline void ForEach(weak_ptr<IGroup> group, const function<void(IShape&)>& func)
{
	WithGroup<IGroup>(group, [&](IGroup& group) {
		CancelableForEach(group, [&](IShape& shape) {
			func(shape);
			return true;
		});
	});
}

inline void CancelableForEach(weak_ptr<IGroup> group, const function<bool(IShape&)>& func)
{
	WithGroup<IGroup>(group, [&](IGroup& group) {
		CancelableForEach(group, func);
	});
}

inline bool IsEmptyGroup(IShape& shape)
{
	auto group = shape.GetGroup();
	return group && group->GetShapeCount() == 0;
}

template<typename VT>
VT GetGroupCommonValue(weak_ptr<IGroup> group, const std::function<VT(IShape& shape)>& getter, const VT& undefinedValue = VT())
{
	VT commonValue = undefinedValue;
	bool first = true;
	CancelableForEach(group, [&](IShape& shape) -> bool {
		if (IsEmptyGroup(shape))
		{
			return true;
		}
		auto value = getter(shape);
		if (first)
		{
			first = false;
			commonValue = value;
		}
		else
		{
			if (commonValue != value) {
				commonValue = undefinedValue;
				return false;
			}
		}
		return true;
	});
	return commonValue;
}

}
}
