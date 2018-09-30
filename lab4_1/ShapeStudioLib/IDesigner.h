#pragma once
#include <istream>
#include "PictureDraft.h"

struct IDesigner
{
	virtual std::unique_ptr<CPictureDraft> CreateDraft(std::istream& strm) const = 0;
	virtual ~IDesigner() = default;
};