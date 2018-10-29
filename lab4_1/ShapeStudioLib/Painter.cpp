#include "stdafx.h"
#include "Painter.h"

namespace painter
{

	CPainter::CPainter()
	{
	}

	void CPainter::DrawPicture(const CPictureDraft& draft, ICanvas& canvas) const
	{
		auto count = draft.GetShapeCount();
		for (decltype(count) idx = 0; idx < count; idx++)
		{
			auto shape = draft.GetShape(idx);
			shape->Draw(canvas);
		}
	}

}