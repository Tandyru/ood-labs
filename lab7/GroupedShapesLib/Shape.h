#pragma once
#include "IShape.h"

namespace shape
{

class CShape : public IShape
{
public:
	CShape();

	// Inherited via IShape
	Rect GetFrame() const override;
	void SetFrame(Rect rect) override;
	shared_ptr<IGroup> GetGroup() override;
	shared_ptr<ILineStyle> GetLineStyle() override;
	shared_ptr<IFillStyle> GetFillStyle() override;

private:
	shared_ptr<ILineStyle> m_lineStyle;
	shared_ptr<IFillStyle> m_fillStyle;
};

}
