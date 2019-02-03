#include "stdafx.h"
#include "DocumentResources.h"
#include <stdio.h>
#include "StringUtils.h"
#include "FileUtils.h"

using namespace std;
using namespace filesystem;

namespace resources
{

CDocumentResources::CDocumentResources(const string& saveFolderName)
	: m_saveFolderName(saveFolderName)
{
	m_tempDirectoryPath = temp_directory_path() / GetUniqueFileName();
	create_directory(m_tempDirectoryPath);
}

CDocumentResources::~CDocumentResources()
{
	remove_all(m_tempDirectoryPath);
}

unique_ptr<IResource> CDocumentResources::AddResource(const Path & originalPath, const string& saveNamePrefix)
{
	const string extension = w2s(originalPath.extension().c_str());
	Path filePath = m_tempDirectoryPath / GetUniqueFileName(extension);
	copy(originalPath, filePath);
	//const string extension = w2s(originalPath.extension().native().c_str());
	return make_unique<CResource>(filePath/*, Path(m_saveFolderName) / (saveNamePrefix + to_string(m_nextResourceNameSuffix++) + extension)*/);
}

Path CDocumentResources::GetDirectoryPath() const
{
	return m_tempDirectoryPath;
}

}
