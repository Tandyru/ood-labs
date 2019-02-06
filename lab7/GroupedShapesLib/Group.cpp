#include "stdafx.h"
#include "Group.h"
#include "GroupLineStyle.h"
#include "GroupFillStyle.h"
#include "Transformations.h"
#include "GroupStyleEnumerator.h"

using namespace std;

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

std::unique_ptr<IEnumerator<IFillStyle>> CGroup::GetFillStyleEnumerator()
{
	return make_unique<CGroupStyleEnumerator<IFillStyle>>(shared_from_this(), [](IShape& shape) {
		return shape.GetFillStyle();
	});
}

std::unique_ptr<IEnumerator<ILineStyle>> CGroup::GetLineStyleEnumerator()
{
	return make_unique<CGroupStyleEnumerator<ILineStyle>>(shared_from_this(), [](IShape& shape) {
		return shape.GetLineStyle();
	});
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
		m_lineStyle = make_shared<CGroupLineStyle>(move(GetLineStyleEnumerator()));
	}
	return m_lineStyle;
}

shared_ptr<IFillStyle> CGroup::GetFillStyle()
{
	if (!m_fillStyle)
	{
		m_fillStyle = make_shared<CGroupFillStyle>(move(GetFillStyleEnumerator()));
	}
	return m_fillStyle;
}

void CGroup::Draw(ICanvas & canvas)
{
	for (auto shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}

shared_ptr<IGroup> CGroup::GetGroup()
{
	return shared_from_this();
}

shared_ptr<const IGroup> CGroup::GetGroup() const
{
	return shared_from_this();
}

}