#pragma once
#include "Shape.h"
#include <vector>

class CPictureDraft
{
public:
	CPictureDraft(std::vector<std::unique_ptr<shape::CShape>>&& shapes);

	size_t GetShapeCount() const;
	std::shared_ptr<shape::CShape> GetShape(size_t idx) const;
private:
	std::vector<std::shared_ptr<shape::CShape>> m_shapes;
};

