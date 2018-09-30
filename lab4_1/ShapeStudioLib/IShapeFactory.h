#pragma once
#include "Shape.h"

struct IShapeFactory
{
	virtual std::unique_ptr<shape::CShape> CreateShape(const std::string& descr) const = 0;

	virtual ~IShapeFactory() = default;
};