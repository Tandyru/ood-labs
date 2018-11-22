#pragma once
#include "ILineStyle.h"

namespace shape
{

class IGroup;

class CGroupLineStyle : public ILineStyle
{
public:
	CGroupLineStyle(weak_ptr<IGroup> group);

	void SetColor(const ColorType& color) override;
	ColorType GetColor() const override;

	void SetThickness(const ILineStyle::ThicknessType& thickness) override;
	ILineStyle::ThicknessType GetThickness() const override;

private:
	weak_ptr<IGroup> m_group;
};

}