#pragma once
#include "Rect.h"
#include "ICanvas.h"
#include "ILineStyle.h"
#include "IFillStyle.h"

namespace shape
{

class IGroup;

class IShape
{
public:
	virtual Rect GetFrame() const = 0;
	virtual void SetFrame(Rect rect) = 0;

	virtual shared_ptr<ILineStyle> GetLineStyle() = 0;
	virtual shared_ptr<IFillStyle> GetFillStyle() = 0;

	virtual void Draw(ICanvas & canvas) const = 0;

	virtual shared_ptr<IGroup> GetGroup() = 0;

	virtual ~IShape() = default;
};

}
