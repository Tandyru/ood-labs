#include "stdafx.h"
#include "Picture.h"

using namespace std;
using namespace shape;

CPicture::CPicture(std::shared_ptr<shape::IGroup>&& root, double originalWidth, double originalHeight)
	: m_root(move(root))
	, m_originalWidth(originalWidth)
	, m_originalHeight(originalHeight)
{
}

void CPicture::Draw(ICanvas & canvas)
{
	canvas.SetOriginalSize(m_originalWidth, m_originalHeight);
	m_root->Draw(canvas);
}

