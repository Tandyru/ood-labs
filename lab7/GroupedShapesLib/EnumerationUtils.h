#pragma once
#include "IEnumerator.h"

namespace shape
{

template<typename VT, typename HT>
VT GetCommonValue(weak_ptr<IEnumerator<HT>> weakEnumerator, const std::function<VT(const HT&)>& getter)
{
	if (auto enumerator = weakEnumerator.lock())
	{
		VT commonValue;
		bool first = true;
		bool commonValueExists = false;
		enumerator->ForEach([&](const HT& holder) {
			auto value = getter(holder);
			if (first)
			{
				commonValue = value;
				commonValueExists = true;
				first = false;
			}
			else if (value != commonValue)
			{
				commonValueExists = false;
			}
		});
		return commonValueExists ? commonValue : VT();
	}
	else
	{
		return VT();
	}
}

}
