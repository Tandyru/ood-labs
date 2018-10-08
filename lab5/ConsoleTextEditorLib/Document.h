#pragma once
#include "IDocument.h"

namespace document
{

	class Document :
		public IDocument
	{
	public:
		Document();
		~Document();
	};

}
