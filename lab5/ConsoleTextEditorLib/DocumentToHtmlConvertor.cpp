#include "stdafx.h"
#include "DocumentToHtmlConvertor.h"
#include "HtmlUtils.h"
#include "StringUtils.h"
#include <fstream>

using namespace filesystem;

namespace document
{
namespace html
{

namespace
{

const auto IMAGES_FOLDER = "images";
const auto IMAGE_FILE_NAME_PREFIX = "image";

void ConvertParagraphToHtml(const IParagraph & paragraph, ostream & out)
{
	out << "	<p>" << EscapeForHtml(paragraph.GetText()) << "</p>" << endl;
}

Path SaveImageFile(const IImage & image, const Path & imagesDirectory, unsigned int imageNumber)
{
	auto sourceImagePath = image.GetPath();
	string extension = w2s(sourceImagePath.extension().native().c_str());
	string destFileName = string(IMAGE_FILE_NAME_PREFIX) + to_string(imageNumber) + extension;
	auto destImagePath = imagesDirectory / destFileName;
	copy(sourceImagePath, destImagePath);
	return relative(destImagePath, imagesDirectory.parent_path());
}

void ConvertImageToHtml(const IImage & image, ostream & out, const Path & imagesDirectory, unsigned int imageNumber)
{
	auto imagePath = SaveImageFile(image, imagesDirectory, imageNumber);
	string imagePathStr = imagePath.generic_string();
	out << "	<img"
		<< " width=\"" << image.GetWidth() << "\""
		<< " height=\"" << image.GetHeight() << "\""
		<< " src=\"" << EscapeForHtml(imagePathStr) << "\""
		<< "/>" << endl;
		;
}

}

void ConvertDocumentToHtml(const impl::IDocumentImpl & document, const Path & htmlFilePath)
{
	auto imagesDirectory = htmlFilePath;
	imagesDirectory.remove_filename();
	imagesDirectory /= IMAGES_FOLDER;
	create_directory(imagesDirectory);

	ofstream strm(htmlFilePath.native(), std::ofstream::out);
	ConvertDocumentToHtml(document, strm, imagesDirectory);
}

void ConvertDocumentToHtml(const impl::IDocumentImpl & document, ostream & out, const Path & imagesDirectory)
{

	out << GetHtmlDocumentHeader(document.GetTitle());
	auto imageNumber = 1;
	auto count = document.GetItemsCount();
	for (decltype(count) index = 0; index < count; index++)
	{
		auto item = document.GetItem(index);
		auto paragraph = item.GetParagraph();
		if (paragraph)
		{
			ConvertParagraphToHtml(*paragraph, out);
		}
		auto image = item.GetImage();
		if (image)
		{
			ConvertImageToHtml(*image, out, imagesDirectory, imageNumber++);
		}
	}
	out << GetHtmlDocumentFooter();
}

}
}
