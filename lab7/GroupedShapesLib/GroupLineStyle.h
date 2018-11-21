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

	void SetLineThickness(const ILineStyle::ThicknessType& thickness) override;
	ILineStyle::ThicknessType GetLineThickness() const override;

private:
	weak_ptr<IGroup> m_group;
};

}