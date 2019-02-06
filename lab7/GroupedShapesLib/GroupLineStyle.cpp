#include "stdafx.h"
#include "GroupLineStyle.h"
#include "IGroup.h"
#include <functional>
#include "EnumerationUtils.h"

namespace shape
{

shape::CGroupLineStyle::CGroupLineStyle(std::unique_ptr<ILineStyleEnumerator>&& enumerator)
	: m_enumerator(move(enumerator))
{
}

void CGroupLineStyle::SetColor(const ColorType & color)
{
	ForEach([&](ILineStyle& lineStyle) {
		lineStyle.SetColor(color);
	});
}

ILineStyle::ColorType CGroupLineStyle::GetColor() const
{
	return GetCommonValue<ILineStyle::ColorType, ILineStyle>(m_enumerator, [](const ILineStyle& lineStyle) {
		return lineStyle.GetColor();
	});
}

void CGroupLineStyle::SetThickness(const ILineStyle::ThicknessType & thickness)
{
	ForEach([&](ILineStyle& lineStyle) {
		lineStyle.SetThickness(thickness);
	});
}

ILineStyle::ThicknessType CGroupLineStyle::GetThickness() const
{
	return GetCommonValue<ILineStyle::ThicknessType, ILineStyle>(m_enumerator, [](const ILineStyle& lineStyle) {
		return lineStyle.GetThickness();
	});
}

void CGroupLineStyle::ForEach(const std::function<void(ILineStyle&)>& func)
{
	if (m_enumerator)
	{
		m_enumerator->ForEach([&](ILineStyle& lineStyle) {
			func(lineStyle);
		});
	}
}

}

