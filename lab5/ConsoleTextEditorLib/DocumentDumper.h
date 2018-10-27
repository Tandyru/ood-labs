#pragma once
#include "IDocument.h"
#include <ostream>

namespace document
{

void DumpDocument(const IDocument& document, std::ostream& out);

}
