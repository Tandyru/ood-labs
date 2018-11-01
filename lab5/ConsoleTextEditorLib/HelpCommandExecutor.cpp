#include "stdafx.h"
#include "SaveInputCommand.h"
#include "HelpCommandExecutor.h"

namespace input_command
{

void ShowCommandHelp(ostream& out)
{
	out << "Available commands:\n"
		"  InsertParagraph <позиция>|end <текст параграфа>\n"
		"  InsertImage <позиция>|end <ширина> <высота> <путь к файлу изображения>\n"
		"  SetTitle <заголовок документа>\n"
		"  ReplaceText <позиция> <текст параграфа>\n"
		"  ResizeImage <позиция> <ширина> <высота>\n"
		"  DeleteItem <позиция>\n"
		"  Undo\n"
		"  Redo\n"
		"  List\n"
		"  Help\n"
		//"  Save <путь>\n"
		;
}

}