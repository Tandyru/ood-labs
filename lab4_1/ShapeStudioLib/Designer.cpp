#include "stdafx.h"
#include "Designer.h"

using namespace std;
using namespace shape;

CDesigner::CDesigner(unique_ptr<IShapeFactory> && shapeFactory)
	: m_shapeFactory(move(shapeFactory))
{
}

std::unique_ptr<CPictureDraft> CDesigner::CreateDraft(std::istream& strm) const
{
	vector<unique_ptr<shape::CShape>> shapes;
	string readline;
	while (getline(strm, readline))
	{
		auto shape = m_shapeFactory->CreateShape(readline);
		shapes.push_back(move(shape));
	}
	return make_unique<CPictureDraft>(move(shapes));
}
