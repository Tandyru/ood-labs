#pragma once
#include "Command.h"

namespace document
{
namespace command
{

class CCommandCombiner
{
public:
	// Inherited via ICommandCombiner
	static bool ShoudCombine(const CCommand & prevCommand, const CCommand & nextCommand);
};

}
}
