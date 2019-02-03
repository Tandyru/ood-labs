#include "stdafx.h"
#include "HtmlUtils.h"
#include <sstream>

using namespace std;

namespace document
{
namespace html
{

string EscapeForHtml(string_view original)
{
	std::string escaped;
	escaped.reserve(original.size());
	for (size_t pos = 0; pos != original.size(); ++pos) {
		switch (original[pos]) {
		case '&':  escaped.append("&amp;");       break;
		case '\"': escaped.append("&quot;");      break;
		case '\'': escaped.append("&apos;");      break;
		case '<':  escaped.append("&lt;");        break;
		case '>':  escaped.append("&gt;");        break;
		default:   escaped.append(&original[pos], 1); break;
		}
	}
	return escaped;
}

string GetHtmlDocumentHeader(string_view title)
{
	stringstream out;
	out << "<!doctype html>" << endl;
	out << R"(<html lang = "ru">)" << endl;
	out << "<head>" << endl;
	out << R"(	<meta charset = "utf-8">)" << endl;
	out << "	<title>" << EscapeForHtml(title) << "</title>" << endl;
	out << "</head>" << endl
		<< "<body>" << endl;
	return out.str();
}

string GetHtmlDocumentFooter()
{
	stringstream out;
	out << "</body>\n"
		<< "</html>\n";
	return out.str();
}

}
}
