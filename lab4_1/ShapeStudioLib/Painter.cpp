#include "stdafx.h"
#include "Painter.h"
#include "ShapePainterFactory.h"

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
			auto painter = CreateShapePainter(*shape);
			if (painter)
			{
				painter(canvas);
			}
		}
	}

}