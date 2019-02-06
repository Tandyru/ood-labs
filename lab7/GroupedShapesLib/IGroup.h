#pragma once
#include "IShape.h"
#include "IEnumerator.h"

namespace shape
{

class IGroup : public IShape
{
public:
	virtual size_t GetShapeCount() const = 0;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const = 0;
	virtual void InsertShapeAtIndex(std::shared_ptr<IShape> shape, size_t index) = 0;
	virtual void RemoveShapeAtIndex(size_t index) = 0;
	virtual std::unique_ptr<IEnumerator<IFillStyle>> GetFillStyleEnumerator() = 0;
	virtual std::unique_ptr<IEnumerator<ILineStyle>> GetLineStyleEnumerator() = 0;
	virtual ~IGroup() = default;
};

}
