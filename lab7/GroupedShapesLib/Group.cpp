#include "stdafx.h"
#include "Group.h"

namespace shape
{

size_t CGroup::GetShapeCount() const
{
	return size_t();
}

shared_ptr<IShape> CGroup::GetShapeAtIndex(size_t index) const
{
	return shared_ptr<IShape>();
}

void CGroup::InsertShapeAtIndex(shared_ptr<IShape> shape, size_t index)
{

	//m_shapes.insert()
}

void CGroup::RemoveShapeAtIndex(size_t index)
{
}

Rect CGroup::GetFrame() const
{
	return Rect();
}

void CGroup::SetFrame(Rect rect)
{
}

shared_ptr<ILineStyle> CGroup::GetLineStyle()
{
	return shared_ptr<ILineStyle>();
}

shared_ptr<IFillStyle> CGroup::GetFillStyle()
{
	return shared_ptr<IFillStyle>();
}

void CGroup::Draw(ICanvas & canvas) const
{
}

shared_ptr<IGroup> CGroup::GetGroup()
{
	return shared_from_this();
}

}