#include "stdafx.h"
#include "StringUtils.h"

std::string w2s(const wchar_t* pwsz)
{
	const auto BUFFER_SIZE = 0x400;
	char buf[BUFFER_SIZE];
	char *pbuf = buf;
	size_t len = wcslen(pwsz) * sizeof(wchar_t) + 1;

	if (len >= sizeof(buf))
	{
		pbuf = const_cast<char*>("error");
	}
	else
	{
		size_t converted;
		wcstombs_s(&converted, buf, pwsz, _TRUNCATE);
	}

	return std::string(pbuf);
}

