#pragma once

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework
{

template<> inline std::wstring ToString<optional<bool>>(const optional<bool>& value)
{
	wstringstream strm;
	strm << (value ? ToString<>(*value) : L"undefined"s).c_str();
	return strm.str();
}

}
}
}
