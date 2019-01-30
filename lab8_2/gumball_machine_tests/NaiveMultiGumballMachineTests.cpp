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

	std::string MakeOutput(unsigned gumballCount, unsigned quarterCount, State state)
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
		std::string suffix = (gumballCount != 1 ? "s" : "");
		std::string suffix2 = (quarterCount != 1 ? "s" : "");
		ss << R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016
Inventory: )" << gumballCount << " gumball" << suffix << " and " <<
quarterCount << " quarter" << suffix2 << R"(
Machine is )" << stateStr;
		return ss.str();
	}

	TEST_METHOD(HasSoldOutStateIfEmptyOnStart)
	{
		CMultiGumballMachine gumballMachine(0);
		Assert::AreEqual(MakeOutput(0, 0, SoldOutState), gumballMachine.ToString());
	}

	TEST_METHOD(HasNoQuarterStateIfNonEmptyOnStart)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		Assert::AreEqual(MakeOutput(ballCount, 0, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(CanSoldTwoGumballsAtOnce)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		Assert::AreEqual(MakeOutput(ballCount, 2, HasQuarterState), gumballMachine.ToString());
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 1, 1, HasQuarterState), gumballMachine.ToString());
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 2, 0, SoldOutState), gumballMachine.ToString());
	}

	TEST_METHOD(CanHoldSeveralQuarters)
	{
		unsigned ballCount = 10;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		gumballMachine.InsertQuarter();
		Assert::AreEqual(MakeOutput(ballCount - 1, 3, HasQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(HasNoQuarterStateAfterAllQuartersEnd)
	{
		unsigned ballCount = 10;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 2, 0, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(DontSellMoreGumballsThenQuatersInserted)
	{
		unsigned ballCount = 10;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		gumballMachine.TurnCrank();
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 2, 0, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(CannotGetMoreThenFiveQuartersAtOnce)
	{
		unsigned ballCount = 10;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		Assert::AreEqual(MakeOutput(ballCount, 5, HasQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(EjectsAllQuartersAtOnce)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.InsertQuarter();
		gumballMachine.EjectQuarter();
		Assert::AreEqual(MakeOutput(ballCount, 0, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToHasQuarterStateFromNoQuarterStateOnInsertQuarter)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		Assert::AreEqual(MakeOutput(ballCount, 1, HasQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToNoQuarterStateFromHasQuarterStateOnEjectQuarter)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.EjectQuarter();
		Assert::AreEqual(MakeOutput(ballCount, 0, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToNoQuarterStateFromHasQuarterStateOnTurnCrank)
	{
		unsigned ballCount = 2;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 1, 0, NoQuarterState), gumballMachine.ToString());
	}

	TEST_METHOD(SetsToSoldOutStateFromHasQuarterStateOnTurnCrankWithLastBall)
	{
		unsigned ballCount = 1;
		CMultiGumballMachine gumballMachine(ballCount);
		gumballMachine.InsertQuarter();
		gumballMachine.TurnCrank();
		Assert::AreEqual(MakeOutput(ballCount - 1, 0, SoldOutState), gumballMachine.ToString());
	}
};
}
