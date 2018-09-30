#include "stdafx.h"
#include "PictureDraft.h"
#include <algorithm>

using namespace std;

CPictureDraft::CPictureDraft(vector<unique_ptr<shape::CShape>>&& shapes)
{
	for (auto& shape : shapes)
	{
		m_shapes.push_back(/*shared_ptr<shape::CShape>(*/move(shape)/*)*/);
	}
	//std::transform(shapes.begin(), shapes.end(), m_shapes.begin(), [](std::unique_ptr<shape::CShape>& shape) {
	//	return std::move(shape);
	//});
}

size_t CPictureDraft::GetShapeCount() const
{
	return m_shapes.size();
}

std::shared_ptr<shape::CShape> CPictureDraft::GetShape(size_t idx) const
{
	return idx < m_shapes.size() ? m_shapes[idx] : std::shared_ptr<shape::CShape>();
}
