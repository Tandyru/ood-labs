#pragma once
#include "IDesigner.h"
#include "IShapeFactory.h"

class CDesigner :
	public IDesigner
{
public:
	CDesigner(const IShapeFactory& shapeFactory);

	// IDesigner
	std::unique_ptr<CPictureDraft> CreateDraft(std::istream& strm) const override;
private:
	const IShapeFactory& m_shapeFactory;
};

