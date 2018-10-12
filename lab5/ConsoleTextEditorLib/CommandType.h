#pragma once

namespace command
{
	enum class CommandType
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

	bool IsNonargCommand(CommandType type);
}