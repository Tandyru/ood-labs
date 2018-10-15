#pragma once

namespace command
{

enum class InputCommandType
{
	InsertParagraph = 1,
	InsertImage, 
	SetTitle,
	List,
	ReplaceText,
	ResizeImage,
	DeleteItem,
	Help,
	Undo,
	Redo,
	Save
};

bool IsNonargCommand(InputCommandType type);

}