#pragma once
#include "IGroup.h"
#include <vector>

namespace shape
{

class CGroup : public std::enable_shared_from_this<CGroup>, public IGroup
{
public:

	// Inherited via IShape
	Rect GetFrame() const override;
	void SetFrame(Rect rect) override;
	std::shared_ptr<ILineStyle> GetLineStyle() override;
	std::shared_ptr<IFillStyle> GetFillStyle() override;
	void Draw(ICanvas & canvas) override;
	std::shared_ptr<IGroup> GetGroup() override;

	// Inherited via IGroup
	size_t GetShapeCount() const override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const override;
	void InsertShapeAtIndex(std::shared_ptr<IShape> shape, size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

private:
	void CheckIndex(size_t index) const;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<ILineStyle> m_lineStyle;
	std::shared_ptr<IFillStyle> m_fillStyle;
};

}