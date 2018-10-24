#pragma once
#include "ICommandCombiner.h"

namespace document
{
namespace command
{

class CCommandCombiner : public ICommandCombiner
{
public:
	// Inherited via ICommandCombiner
	virtual unique_ptr<CCommand> Combine(const CCommand & prevCommand, const CCommand & nextCommand) const override;
};

}
}
