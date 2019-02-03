#pragma once

namespace document
{
namespace html
{

std::string EscapeForHtml(std::string_view original);
std::string GetHtmlDocumentHeader(std::string_view title);
std::string GetHtmlDocumentFooter();

}
}
