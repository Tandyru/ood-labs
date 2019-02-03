#include "stdafx.h"
#include "FileUtils.h"

using namespace std;

string GetUniqueFileName(const string & extension)
{
	char buffer[L_tmpnam];
	tmpnam_s(buffer, L_tmpnam);
	return string(buffer) + extension;
}
