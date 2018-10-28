#include "stdafx.h"
#include "DocumentDumper.h"
#include "Document.h"

namespace document
{

namespace
{

ostream& operator<<(ostream& out, const CConstDocumentItem& item)
{
	if (auto paragraph = item.GetParagraph())
	{
		out << "Paragraph: " << paragraph->GetText();
		return out;
	}
	else if (auto image = item.GetImage())
	{
		out << "Image: " << image->GetWidth() << " " << image->GetHeight() << " " << image->GetPath().string();
		return out;
	}
	throw logic_error("Dcoument item is not a paragraph or image");
}

}

void DumpDocument(const IDocument& document, ostream& out)
{
	out << "Title: " << document.GetTitle() << endl;
	for (size_t index = 0; index < document.GetItemsCount(); index++)
	{
		auto item = document.GetItem(index);
		out << index << ". " << item << endl;
	}
}

}
