#include "stdafx.h"
#include "InsertImageCommand.h"
#include "IDocumentImpl.h"

using namespace std;

namespace document
{
namespace command
{

CInsertImageCommand::CInsertImageCommand(impl::IDocumentImpl & document, optional<size_t> position, 
	std::shared_ptr<IImage> image)
	: m_document(document)
	, m_position(position)
	, m_image(image)
{
}

void CInsertImageCommand::ExecuteImpl()
{
	m_insertedPosition = m_position ? *m_position : m_document.GetItemsCount();
	m_document.InsertImage(m_image, m_insertedPosition);
}

void CInsertImageCommand::UnexecuteImpl()
{
	m_document.DeleteItem(m_insertedPosition);
}

}
}
