#include "stdafx.h"
#include "Triangle.h"
#include "Transformations.h"

namespace shape
{

using namespace transform;

CTriangle::CTriangle(Point vertex1, Point vertex2, Point vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

Rect CTriangle::GetFrame() const
{
	Rect result(m_vertex1);
	result += m_vertex2;
	result += m_vertex3;
	return result;
}

void CTriangle::SetFrame(Rect rect)
{
	const auto oldRect = GetFrame();
	m_vertex1 = TransformVertexToNewRect(m_vertex1, oldRect, rect);
	m_vertex2 = TransformVertexToNewRect(m_vertex2, oldRect, rect);
	m_vertex3 = TransformVertexToNewRect(m_vertex3, oldRect, rect);
}

void CTriangle::Draw(ICanvas & canvas) const
{
	// ??
}

}
