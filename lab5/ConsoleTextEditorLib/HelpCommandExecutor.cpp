#include "stdafx.h"
#include "SaveInputCommand.h"
#include "HelpCommandExecutor.h"

namespace input_command
{

void ShowCommandHelp(ostream& out)
{
	out << "Available commands:\n"
		"  InsertParagraph <������>|end <⥪�� ��ࠣ��>\n"
		"  InsertImage <������>|end <�ਭ�> <����> <���� � 䠩�� ����ࠦ����>\n"
		"  SetTitle <��������� ���㬥��>\n"
		"  ReplaceText <������> <⥪�� ��ࠣ��>\n"
		"  ResizeImage <������> <�ਭ�> <����>\n"
		"  DeleteItem <������>\n"
		"  Undo\n"
		"  Redo\n"
		"  List\n"
		"  Help\n"
		//"  Save <����>\n"
		;
}

}