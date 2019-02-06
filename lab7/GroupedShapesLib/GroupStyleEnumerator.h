#pragma once
#include "IEnumerator.h"

namespace shape
{

template<typename SI>
class CGroupStyleEnumerator : public IEnumerator<SI> {
public:
	CGroupStyleEnumerator(std::weak_ptr<IGroup> group, const std::function<std::shared_ptr<SI>(IShape& shape)>& getter)
		: m_group(group)
		, m_getter(getter)
	{
	}

	void ForEach(const std::function<void(const SI&)>& func) const override
	{
		if (auto group = m_group.lock())
		{
			auto count = group->GetShapeCount();
			for (decltype(count) index = 0; index < count; index++)
			{
				auto shape = group->GetShapeAtIndex(index);
				if (shape)
				{
					func(*m_getter(*shape));
				}
			}
		}
	}

	void ForEach(const std::function<void(SI&)>& func) override
	{
		if (auto group = m_group.lock())
		{
			auto count = group->GetShapeCount();
			for (decltype(count) index = 0; index < count; index++)
			{
				auto shape = group->GetShapeAtIndex(index);
				if (shape)
				{
					func(*m_getter(*shape));
				}
			}
		}
	}
private:
	std::weak_ptr<IGroup> m_group;
	std::function<std::shared_ptr<SI>(IShape& shape)> m_getter;
};

}
