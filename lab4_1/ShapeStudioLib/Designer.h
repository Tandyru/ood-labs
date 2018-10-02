#pragma once
#include "IDesigner.h"
#include "IShapeFactory.h"

class CDesigner :
	public IDesigner
{
public:
	CDesigner(std::unique_ptr<IShapeFactory> && shapeFactory);

	// IDesigner
	std::unique_ptr<CPictureDraft> CreateDraft(std::istream& strm) const override;
private:
	std::unique_ptr<IShapeFactory> m_shapeFactory;
};

