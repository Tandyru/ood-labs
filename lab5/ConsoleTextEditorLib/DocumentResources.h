#pragma once
#include "Resource.h"

namespace resources
{

class CDocumentResources
{
public:
	CDocumentResources(const std::string& saveFolderName = "images");
	~CDocumentResources();

	std::unique_ptr<IResource> AddResource(const Path& originalPath, const std::string& saveNamePrefix);

	// For testing purposes only
	Path GetDirectoryPath() const;

private:
	Path m_tempDirectoryPath;
	std::string m_saveFolderName;
	unsigned int m_nextResourceNameSuffix = 1;
};

}
