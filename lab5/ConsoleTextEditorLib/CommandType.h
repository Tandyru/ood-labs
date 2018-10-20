#pragma once

namespace document
{

enum class CommandType
{
	InsertParagraph = 1,
	InsertImage, 
	SetTitle,
	ReplaceText,
	ResizeImage,
	DeleteItem,
};

}