#include "stdafx.h"
#include "../gumball_machine/GumBallMachineWithDynamicallyCreatedState.h"
#include "GambleMachineMock.h"
#include "TestOutStream.h"
#include "CppUnitTest.h"

using namespace with_dynamic_state;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gumball_machine_tests
{

TEST_CLASS(GumballMachineTests)
{
	TestOutStream out;
	enum State {
		SoldOutState,
		NoQuarterState,
		SoldState,
		HasQuarterState
	};

public:

	std::string MakeOutput(unsigned count, State state)
	{
		CGumballMachineMock gumballMachineMock;
		std::string stateStr;
		switch (state) {
		case SoldOutState:
			stateStr = CSoldOutState(gumballMachineMock).ToString();
			break;
		case NoQuarterState:
			stateStr = CNoQuarterState(gumballMachineMock).ToString();
			break;
		case SoldState:
			stateStr = CSoldState(gumballMachineMock).ToString();
			break;
		case HasQuarterState:
			stateStr = CHasQuarterState(gumballMachineMock).ToString();
			break;
		};
		std::stringstream ss;
		std::string suffix = (count != 1 ? "s" : "");
		ss << R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: )" << count << " gumball" << suffix << R"(
Machine is )" << stateStr;
		return ss.str();
	}

	TEST_METHOD(HasSoldOutStateIfEmptyOnStart)
	{
		CGumballMachine gumballMachine(0);
		Assert::AreEqual(MakeOutput(0, SoldOutState), gumballMachine.ToString());
	}

	TEST_METHOD(HasNoQuarterStateIfNonEmptyOnStart)
	{
		unsigned ballCount = 2;
		CGumballMachine gumballMachine(ballCount);
		Assert::AreEqual(MakeOutput(ballCount, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToHasQuarterStateFromNoQuarterStateOnInsertQuarter)
	{
		unsigned ballCount = 2;
		CGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		Assert::AreEqual(MakeOutput(ballCount, HasQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToNoQuarterStateFromHasQuarterStateOnEjectQuarter)
	{
		unsigned ballCount = 2;
		CGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.EjectQuarter();
		Assert::AreEqual(MakeOutput(ballCount, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToNoQuarterStateFromHasQuarterStateOnTurnCrank)
	{
		unsigned ballCount = 2;
		CGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 1, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToSoldOutStateFromHasQuarterStateOnTurnCrankWithLastBall)
	{
		unsigned ballCount = 1;
		CGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 1, SoldOutState), gumballMachine.ToString());
	}
};
}
