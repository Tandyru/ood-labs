#include "stdafx.h"
#include "../gumball_machine/GumBallMachineWithDynamicallyCreatedState.h"
#include "GambleMachineMock.h"
#include "TestOutStream.h"
#include "CppUnitTest.h"

using namespace with_dynamic_state;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gumball_machine_tests
{		
	TEST_CLASS(SoldOutStateTests)
	{
		TestOutStream out;
		CGumballMachineMock gumballMachineMock;

	public:
		
		TEST_METHOD(TestSoldOutStateOnInsertQuarterReaction)
		{
			CSoldOutState state(gumballMachineMock);
			state.InsertQuarter();
			Assert::AreEqual("You can't insert a quarter, the machine is sold out\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}

		TEST_METHOD(TestSoldOutStateOnEjectQuarterReaction)
		{
			CSoldOutState state(gumballMachineMock);
			state.EjectQuarter();
			Assert::AreEqual("You can't eject, you haven't inserted a quarter yet\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}

		TEST_METHOD(TestSoldOutStateOnTurnCrankReaction)
		{
			CSoldOutState state(gumballMachineMock);
			state.TurnCrank();
			Assert::AreEqual("You turned but there's no gumballs\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}

		TEST_METHOD(TestSoldOutStateOnDispenseReaction)
		{
			CSoldOutState state(gumballMachineMock);
			state.Dispense();
			Assert::AreEqual("No gumball dispensed\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}
	};
}