#pragma once
#include "../gumball_machine/MultiGumBallMachineWithDynamicallyCreatedState.h"

class CGumballMachineMock : public with_dynamic_state::IMultiGumballMachine
{
public:
	bool releaseBallCalled = false;
	bool soldOutStateSet = false;
	bool noQuarterStateSet = false;
	bool soldStateSet = false;
	bool hasQuarterStateSet = false;
	unsigned ballCount = 1;

	void ReleaseBall() override 
	{
		if (ballCount > 0)
		{
			--ballCount;
		}
		releaseBallCalled = true;
	}
	
	unsigned GetBallCount()const override
	{
		return ballCount;
	}

	void SetSoldOutState() override
	{
		soldOutStateSet = true;
	}

	void SetNoQuarterState() override
	{
		noQuarterStateSet = true;
	}

	void SetSoldState() override
	{
		soldStateSet = true;
	}

	void SetHasQuarterState() override
	{
		hasQuarterStateSet = true;
	}

	bool IsStateChanged() const
	{
		return soldOutStateSet || noQuarterStateSet || soldStateSet || hasQuarterStateSet;
	}

};