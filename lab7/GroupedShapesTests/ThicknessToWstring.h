#pragma once
#include "../GroupedShapesLib/ILineStyle.h"

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework
{

template<> inline std::wstring ToString<shape::ILineStyle::ThicknessType>(const shape::ILineStyle::ThicknessType& thickness)
{
	wstringstream strm;
	strm << (thickness ? to_wstring(*thickness) : L"undefined"s).c_str();
	return strm.str();
}

}
}
}
