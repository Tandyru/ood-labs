#include "stdafx.h"
#include "Shape.h"
#include "LineStyle.h"
#include "FillStyle.h"
#include "IGroup.h"

namespace shape
{

CShape::CShape()
	: m_lineStyle(make_shared<CLineStyle>())
	, m_fillStyle(make_shared<CFillStyle>(Color{ 127, 127, 127, 255 }, true))
{
}

Rect CShape::GetFrame() const
{
	return Rect();
}

void CShape::SetFrame(Rect rect)
{
}

shared_ptr<IGroup> CShape::GetGroup()
{
	return shared_ptr<IGroup>();
}

shared_ptr<const IGroup> CShape::GetGroup() const
{
	return shared_ptr<const IGroup>();
}

shared_ptr<ILineStyle> CShape::GetLineStyle()
{
	return m_lineStyle;
}

shared_ptr<IFillStyle> CShape::GetFillStyle()
{
	return m_fillStyle;
}

void CShape::Draw(ICanvas & canvas)
{
	auto group = GetGroup();
	if (group)
	{
		auto count = group->GetShapeCount();
		for (decltype(count) index = 0; index < count; index++)
		{
			auto shape = group->GetShapeAtIndex(index);
			shape->Draw(canvas);
		}
	}
	else
	{
		auto fillStyleColor = GetFillStyle()->GetColor();
		auto fillColor = fillStyleColor ? *fillStyleColor : shape::NONE_COLOR;
		auto fill = GetFillStyle()->GetFill();
		if (fill && *fill && fillStyleColor)
		{
			canvas.SetFillColor(fillColor);
		}

		auto lineStyleColor = GetLineStyle()->GetColor();
		canvas.SetDrawColor(lineStyleColor ? *lineStyleColor : shape::NONE_COLOR);

		auto lineThickness = GetLineStyle()->GetThickness();
		auto thickness = lineThickness ? *lineThickness : NO_LINE_THICKNESS_VALUE;
		canvas.SetLineThickness(thickness);

		DrawImpl(canvas);
	}
}

}