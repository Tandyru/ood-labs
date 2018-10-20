#pragma once
#include "Command.h"

namespace command
{

class ICommandHistory
{
public:
	virtual void Do(unique_ptr<CCommand>&& command) = 0;

	virtual ~ICommandHistory() = default;
};

}