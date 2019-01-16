#include "stdafx.h"
#include "Group.h"
#include "GroupLineStyle.h"
#include "GroupFillStyle.h"
#include "Transformations.h"

namespace shape
{

using namespace transform;

void CGroup::CheckIndex(size_t index) const
{
	if (index >= m_shapes.size())
	{
		throw runtime_error("Out of range");
	}
}

size_t CGroup::GetShapeCount() const
{
	return m_shapes.size();
}

shared_ptr<IShape> CGroup::GetShapeAtIndex(size_t index) const
{
	CheckIndex(index);
	return m_shapes[index];
}

void CGroup::InsertShapeAtIndex(shared_ptr<IShape> shape, size_t index)
{
	if (index > m_shapes.size())
	{
		throw runtime_error("Out of range");
	}
	m_shapes.insert(m_shapes.begin() + index, shape);
}

void CGroup::RemoveShapeAtIndex(size_t index)
{
	CheckIndex(index);
	m_shapes.erase(m_shapes.begin() + index);
}

Rect CGroup::GetFrame() const
{
	Rect result;

	bool first = true;
	for (auto shape : m_shapes)
	{
		const auto frame = shape->GetFrame();
		if (first) 
		{
			result = frame;
		}
		else
		{
			result += frame;
		}
		first = false;
	}
	return result;
}

void CGroup::SetFrame(Rect rect)
{
	auto originalFrame = GetFrame();

	for (auto shape : m_shapes)
	{
		auto shapeRect = shape->GetFrame();
		shape->SetFrame(TransformRect(shapeRect, originalFrame, rect));
	}
}

shared_ptr<ILineStyle> CGroup::GetLineStyle()
{
	if (!m_lineStyle)
	{
		m_lineStyle = make_shared<CGroupLineStyle>(shared_from_this());
	}
	return m_lineStyle;
}

shared_ptr<IFillStyle> CGroup::GetFillStyle()
{
	if (!m_fillStyle)
	{
		m_fillStyle = make_shared<CGroupFillStyle>(shared_from_this());
	}
	return m_fillStyle;
}

void CGroup::Draw(ICanvas & canvas)
{
}

shared_ptr<IGroup> CGroup::GetGroup()
{
	return shared_from_this();
}

}