#pragma once
#include "../GroupedShapesLib/Color.h"

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework
{

template<> inline std::wstring ToString<shape::Color>(const shape::Color& color)
{
	wstringstream strm;
	strm << L"Color("
		<< to_wstring(color.r) << ","
		<< to_wstring(color.g) << ","
		<< to_wstring(color.b) << ","
		<< to_wstring(color.a) << ")";
	return strm.str();
}

template<> inline std::wstring ToString<optional<shape::Color>>(const optional<shape::Color>& color)
{
	wstringstream strm;
	if (!color)
	{
		strm << L"undefined";
	}
	else
	{
		strm << L"Color("
			<< to_wstring(color->r) << ","
			<< to_wstring(color->g) << ","
			<< to_wstring(color->b) << ","
			<< to_wstring(color->a) << ")";
	}
	return strm.str();
}

}
}
}
