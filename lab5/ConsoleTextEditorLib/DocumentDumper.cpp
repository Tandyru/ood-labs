#include "stdafx.h"
#include "DocumentDumper.h"
#include "Document.h"
#include "StringUtils.h"

namespace document
{

namespace
{

const auto IMAGES_FOLDER = "images";
const auto IMAGE_FILE_NAME_PREFIX = "image";

unsigned int g_imageNumber = 1;

string GenerateImageOutputPath(unsigned int imageNumber, string_view extension)
{
	return string(IMAGES_FOLDER) + "/" + IMAGE_FILE_NAME_PREFIX + to_string(imageNumber) + string(extension);
}

ostream& operator<<(ostream& out, const CConstDocumentItem& item)
{
	if (auto paragraph = item.GetParagraph())
	{
		out << "Paragraph: " << paragraph->GetText();
		return out;
	}
	else if (auto image = item.GetImage())
	{
		auto imagePath = image->GetPath();
		string extension = w2s(imagePath.extension().native().c_str());
		//GenerateImageOutputPath(g_imageNumber++, extension);
		out << "Image: " << image->GetWidth() << " " << image->GetHeight() << " " << w2s(imagePath.c_str());
		return out;
	}
	throw logic_error("Dcoument item is not a paragraph or image");
}

}

void DumpDocument(const IDocument& document, ostream& out)
{
	out << "Title: " << document.GetTitle() << endl;
	g_imageNumber = 1;
	for (size_t index = 0; index < document.GetItemsCount(); index++)
	{
		auto item = document.GetItem(index);
		out << index << ". " << item << endl;
	}
}

}
