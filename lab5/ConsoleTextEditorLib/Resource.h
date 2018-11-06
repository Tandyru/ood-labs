#pragma once
#include "IResource.h"

namespace resources
{

class CResource : public IResource
{
public:
	CResource(const Path& path, const Path& savePath);
	~CResource();

	Path GetFilePath() const override;
	Path GetSavePath() const override;
private:
	Path m_path;
	Path m_savePath;
};

}
