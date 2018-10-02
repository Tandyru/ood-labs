#pragma once
#include "../ShapeStudioLib/PictureDraft.h"
#include <memory>

class PictureDraftLoader
{
public:
	static std::unique_ptr<CPictureDraft> LoadFromFile(const std::wstring& filePath);
};

