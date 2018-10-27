#include "stdafx.h"
#include "DocumentDumper.h"
#include "Document.h"

namespace document
{

void DumpDocument(const IDocument& document, ostream& out)
{
	out << "Title: " << document.GetTitle();
	for (size_t index = 0; index < document.GetItemsCount(); index++)
	{
		auto item = document.GetItem(index);
		// TODO:
	}
}

}
