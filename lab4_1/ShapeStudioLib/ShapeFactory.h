#pragma once
#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory 
{
public:
	CShapeFactory();

	std::unique_ptr<shape::CShape> CreateShape(const std::string& descr) const override;

};

