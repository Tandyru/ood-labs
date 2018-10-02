#include "stdafx.h"
#include "ShapeFactory.h"
#include "ShapeSerializers.h"
#include "MapEnum.h"
#include <regex>

using namespace std;
using namespace shape;
using namespace shape_serializer;

typedef unique_ptr<CShape> (*Creator)(const string&);

const pair<const char*, Creator> shapeCreators[] = {
	{ RectangleSerializer::STRING_ID, RectangleSerializer::Create },
};

CShapeFactory::CShapeFactory()
{
}

unique_ptr<shape::CShape> CShapeFactory::CreateShape(const string& descr) const
{
	regex re(R"r(^\s*\{"([^"]+))r");
	smatch sm;
	if(!regex_search(descr, sm, re))
	{
		throw exception("Invalid shape description format");
	}
	if (sm.size() < 2)
	{
		throw exception("Invalid shape description format");
	}
	const string type = sm[1];

	Creator creator;
	try
	{
		creator = StringMapEnum(shapeCreators, type);
	}
	catch (exception)
	{
		throw UnknownShapeTypeException(type);
	}
	return creator(descr);
}
