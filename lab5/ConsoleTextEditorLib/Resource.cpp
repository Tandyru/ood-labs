#include "stdafx.h"
#include "Resource.h"

using namespace std;

namespace resources
{

CResource::CResource(const Path& path/*, const Path& savePath*/)
	: m_path(path)
	//, m_savePath(savePath)
{
}

CResource::~CResource()
{
	filesystem::remove(m_path);
}

Path CResource::GetFilePath() const
{
	return m_path;
}

//Path CResource::GetSavePath() const
//{
//	return m_savePath;
//}

}
