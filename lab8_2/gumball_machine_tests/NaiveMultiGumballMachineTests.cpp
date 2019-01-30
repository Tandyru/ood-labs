#include "stdafx.h"
#include "../gumball_machine/NaiveMultiGumBallMachine.h"
#include "GambleMachineMock.h"
#include "TestOutStream.h"
#include "CppUnitTest.h"

using namespace naive;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gumball_machine_tests
{

TEST_CLASS(NaiveMultiGumballMachineTests)
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
			stateStr = "sold out";
			break;
		case NoQuarterState:
			stateStr = "waiting for quarter";
			break;
		case SoldState:
			stateStr = "delivering a gumball";
			break;
		case HasQuarterState:
			stateStr = "waiting for turn of crank";
			break;
		};
		std::stringstream ss;
		std::string suffix = (count != 1 ? "s" : "");
		ss << R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016
Inventory: )" << count << " gumball" << suffix << R"(
Machine is )" << stateStr;
		return ss.str();
	}

	TEST_METHOD(HasSoldOutStateIfEmptyOnStart)
	{
		CMultiGumballMachine gumballMachine(0);
		Assert::AreEqual(MakeOutput(0, SoldOutState), gumballMachine.ToString());
	}

	TEST_METHOD(HasNoQuarterStateIfNonEmptyOnStart)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		Assert::AreEqual(MakeOutput(ballCount, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToHasQuarterStateFromNoQuarterStateOnInsertQuarter)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		Assert::AreEqual(MakeOutput(ballCount, HasQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToNoQuarterStateFromHasQuarterStateOnEjectQuarter)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.EjectQuarter();
		Assert::AreEqual(MakeOutput(ballCount, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToNoQuarterStateFromHasQuarterStateOnTurnCrank)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 1, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToSoldOutStateFromHasQuarterStateOnTurnCrankWithLastBall)
	{
		unsigned ballCount = 1;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 1, SoldOutState), gumballMachine.ToString());
	}
};
}
