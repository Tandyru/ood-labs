#include "stdafx.h"
#include "DocumentImageItemMock.h"

DocumentImageItemMock::DocumentImageItemMock()
	: document::CDocumentItem(make_shared<document::CImage>(nullptr, 320, 200))
{
}
