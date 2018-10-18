#pragma once

namespace command
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