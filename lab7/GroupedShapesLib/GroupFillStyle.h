#pragma once
#include "IFillStyle.h"
#include "IEnumerator.h"

namespace shape
{

class IGroup;

class CGroupFillStyle : public IFillStyle
{
	using IFillStyleEnumerator = IEnumerator<IFillStyle>;
public:
	CGroupFillStyle(std::unique_ptr<IFillStyleEnumerator>&& enumerator);

	void SetColor(const ColorType& color) override;
	ColorType GetColor() const override;

	void SetFill(const IFillStyle::FillType& fill) override;
	IFillStyle::FillType GetFill() const override;

private:
	void ForEach(const std::function<void(const IFillStyle&)>& func) const;
	void ForEach(const std::function<void(IFillStyle&)>& func);

private:
	std::unique_ptr<IFillStyleEnumerator> m_enumerator;
};

}