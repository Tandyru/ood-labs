#include "stdafx.h"
#include "PictureDraftLoader.h"
#include "../ShapeStudioLib/Designer.h"
#include "../ShapeStudioLib/ShapeFactory.h"
#include <fstream>

using namespace std;

unique_ptr<CPictureDraft> PictureDraftLoader::LoadFromFile(const wstring& filePath)
{
	ifstream strm;
	strm.open(filePath, std::ifstream::in);
	if (!strm.is_open())
	{
		throw std::exception("File not found");
	}

	CDesigner designer(make_unique<CShapeFactory>());

	return designer.CreateDraft(strm);
}
