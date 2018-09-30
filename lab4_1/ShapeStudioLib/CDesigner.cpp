#include "stdafx.h"
#include "CDesigner.h"

using namespace std;
using namespace shape;

CDesigner::CDesigner(const IShapeFactory& shapeFactory)
	: m_shapeFactory(shapeFactory)
{
}

std::unique_ptr<CPictureDraft> CDesigner::CreateDraft(std::istream& strm) const
{
	vector<unique_ptr<shape::CShape>> shapes;
	string readline;
	while (getline(strm, readline))
	{
		auto shape = m_shapeFactory.CreateShape(readline);
		shapes.push_back(move(shape));
	}
	return make_unique<CPictureDraft>(move(shapes));
}
