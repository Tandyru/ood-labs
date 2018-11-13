#pragma once
#include "IShape.h"

namespace shape
{

class CShape : public IShape
{
public:
	// Inherited via IShape
	Rect GetFrame() const override;
	void SetFrame(Rect rect) override;
	shared_ptr<IGroup> GetGroup() override;
	shared_ptr<ILineStyle> GetLineStyle() override;
	shared_ptr<IFillStyle> GetFillStyle() override;

};

}
