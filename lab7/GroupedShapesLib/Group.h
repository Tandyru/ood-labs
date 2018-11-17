#pragma once
#include "IGroup.h"
#include <vector>

namespace shape
{

class CGroup : public enable_shared_from_this<CGroup>, public IGroup
{
public:
	// Inherited via IShape
	Rect GetFrame() const override;
	void SetFrame(Rect rect) override;
	shared_ptr<ILineStyle> GetLineStyle() override;
	shared_ptr<IFillStyle> GetFillStyle() override;
	void Draw(ICanvas & canvas) const override;
	shared_ptr<IGroup> GetGroup() override;

	// Inherited via IGroup
	size_t GetShapeCount() const override;
	shared_ptr<IShape> GetShapeAtIndex(size_t index) const override;
	void InsertShapeAtIndex(shared_ptr<IShape> shape, size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

private:
	void CheckIndex(size_t index) const;

private:
	vector<shared_ptr<IShape>> m_shapes;
};

}