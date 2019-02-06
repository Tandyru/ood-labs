#include "stdafx.h"
#include "GroupFillStyle.h"
#include "EnumerationUtils.h"

namespace shape
{

CGroupFillStyle::CGroupFillStyle(weak_ptr<IFillStyleEnumerator> enumerator)
	: m_enumerator(enumerator)
{
}

void CGroupFillStyle::SetColor(const ColorType & color)
{
	ForEach([&](IFillStyle& fillStyle) {
		fillStyle.SetColor(color);
	});
}

IFillStyle::ColorType CGroupFillStyle::GetColor() const
{
	return GetCommonValue<IFillStyle::ColorType, IFillStyle>(m_enumerator, [](const IFillStyle& fillStyle) {
		return fillStyle.GetColor();
	});
}

void CGroupFillStyle::SetFill(const FillType & fill)
{
	ForEach([&](IFillStyle& fillStyle) {
		fillStyle.SetFill(fill);
	});
}

IFillStyle::FillType CGroupFillStyle::GetFill() const
{
	return GetCommonValue<IFillStyle::FillType, IFillStyle>(m_enumerator, [](const IFillStyle& fillStyle) {
		return fillStyle.GetFill();
	});
}

void CGroupFillStyle::ForEach(const std::function<void(const IFillStyle&)>& func) const
{
	if (auto enumerator = m_enumerator.lock())
	{
		enumerator->ForEach([&](const IFillStyle& fillStyle) {
			func(fillStyle);
		});
	}
}

void CGroupFillStyle::ForEach(const std::function<void(IFillStyle&)>& func)
{
	if (auto enumerator = m_enumerator.lock())
	{
		enumerator->ForEach([&](IFillStyle& fillStyle) {
			func(fillStyle);
		});
	}
}

}

