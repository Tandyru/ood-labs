#pragma once

namespace input_command
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
	Save,
	Exit
};

bool IsNonargCommand(InputCommandType type);

}