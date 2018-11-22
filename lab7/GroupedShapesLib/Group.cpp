#include "stdafx.h"
#include "Group.h"
#include "GroupLineStyle.h"

namespace shape
{

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
	// TODO:
	throw runtime_error("Not implemented");
	return Rect();
}

void CGroup::SetFrame(Rect rect)
{
	// TODO:
	throw runtime_error("Not implemented");
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
	// TODO:
	throw runtime_error("Not implemented");
	return shared_ptr<IFillStyle>();
}

void CGroup::Draw(ICanvas & canvas) const
{
	// TODO:
	throw runtime_error("Not implemented");
}

shared_ptr<IGroup> CGroup::GetGroup()
{
	return shared_from_this();
}

}