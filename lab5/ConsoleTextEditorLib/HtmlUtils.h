#pragma once

namespace document
{
namespace html
{

string EscapeForHtml(string_view original);
string GetHtmlDocumentHeader(string_view title);
string GetHtmlDocumentFooter();

}
}
