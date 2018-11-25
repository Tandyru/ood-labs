#pragma once
#include "IFillStyle.h"

namespace shape
{

class IGroup;

class CGroupFillStyle : public IFillStyle
{
public:
	CGroupFillStyle(weak_ptr<IGroup> group);

	void SetColor(const ColorType& color) override;
	ColorType GetColor() const override;

	void SetFill(const IFillStyle::FillType& fill) override;
	IFillStyle::FillType GetFill() const override;

private:
	weak_ptr<IGroup> m_group;
};

}