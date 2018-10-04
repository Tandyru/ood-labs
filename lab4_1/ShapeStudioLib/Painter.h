#pragma once
#include "IPainter.h"

namespace painter
{

	class CPainter : public IPainter
	{
	public:
		CPainter();

		void DrawPicture(const CPictureDraft& draft, ICanvas& canvas) const override;
	};

}