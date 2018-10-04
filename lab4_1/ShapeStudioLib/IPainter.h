#pragma once
#include "PictureDraft.h"
#include "ICanvas.h"

namespace painter
{
	struct IPainter
	{
		virtual void DrawPicture(const CPictureDraft& draft, ICanvas& canvas) const = 0;

		virtual ~IPainter() = default;
	};

}
