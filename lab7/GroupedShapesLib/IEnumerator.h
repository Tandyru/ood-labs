#pragma once
#include <functional>

namespace shape
{

template<typename T>
struct IEnumerator
{
	virtual void ForEach(const std::function<void(const T&)>& func) const = 0;
	virtual void ForEach(const std::function<void(T&)>& func) = 0;
};
}
