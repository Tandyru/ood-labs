#pragma once
#include "Rect.h"

namespace shape
{

struct IShape
{
	virtual Rect GetFrame() const = 0;
	virtual void SetFrame(Rect rect) = 0;

	//virtual shared_ptr<ILineStyle>

	virtual ~IShape() = default;
};

}
