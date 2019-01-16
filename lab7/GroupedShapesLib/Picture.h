#pragma once
#include "IGroup.h"
#include "ICanvas.h"

class CPicture
{
public:
	CPicture(std::shared_ptr<shape::IGroup>&& root, double originalWidth, double originalHeight);

	void Draw(shape::ICanvas& canvas);

private:
	std::shared_ptr<shape::IGroup> m_root;
	double m_originalWidth;
	double m_originalHeight;
};