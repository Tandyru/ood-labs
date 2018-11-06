#pragma once
#include "Resource.h"

namespace resources
{

class CDocumentResources
{
public:
	CDocumentResources(const string& saveFolderName = "images");
	~CDocumentResources();

	unique_ptr<IResource> AddResource(const Path& originalPath, const string& saveNamePrefix);

	// For testing purposes only
	Path GetDirectoryPath() const;

private:
	static string GetUniqueFileName();

private:
	Path m_tempDirectoryPath;
	string m_saveFolderName;
	unsigned int m_nextResourceNameSuffix = 1;
};

}
