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
	std::shared_ptr<IGroup> GetGroup() override;
	std::shared_ptr<const IGroup> GetGroup() const override;
	std::shared_ptr<ILineStyle> GetLineStyle() override;
	std::shared_ptr<IFillStyle> GetFillStyle() override;

	void Draw(ICanvas & canvas) override;

protected: 
	virtual void DrawImpl(ICanvas & canvas) = 0;

private:
	std::shared_ptr<ILineStyle> m_lineStyle;
	std::shared_ptr<IFillStyle> m_fillStyle;
};

}
