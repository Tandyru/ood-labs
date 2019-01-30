#include "stdafx.h"
#include "../gumball_machine/MultiGumBallMachineWithDynamicallyCreatedState.h"
#include "GambleMachineMock.h"
#include "TestOutStream.h"
#include "CppUnitTest.h"

using namespace with_dynamic_state;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gumball_machine_tests
{		
	TEST_CLASS(SoldStateTests)
	{
		TestOutStream out;
		CGumballMachineMock gumballMachineMock;

	public:
		
		TEST_METHOD(TestSoldStateOnInsertQuarterReaction)
		{
			CSoldState state(gumballMachineMock);
			state.InsertQuarter();
			Assert::AreEqual("Please wait, we're already giving you a gumball\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}

		TEST_METHOD(TestSoldStateOnEjectQuarterReaction)
		{
			CSoldState state(gumballMachineMock);
			state.EjectQuarter();
			Assert::AreEqual("Sorry you already turned the crank\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}

		TEST_METHOD(TestSoldStateOnTurnCrankReaction)
		{
			CSoldState state(gumballMachineMock);
			state.TurnCrank();
			Assert::AreEqual("Turning twice doesn't get you another gumball\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}

		TEST_METHOD(TestSoldStateOnDispenseReactionForEmptyMachine)
		{
			gumballMachineMock.ballCount = 0;
			CSoldState state(gumballMachineMock);
			state.Dispense();
			Assert::AreEqual("Oops, out of gumballs\n", out);
			Assert::IsTrue(gumballMachineMock.soldOutStateSet);
			Assert::IsFalse(gumballMachineMock.noQuarterStateSet);
		}

		TEST_METHOD(TestSoldStateOnDispenseReactionForNonEmptyMachine)
		{
			gumballMachineMock.ballCount = 2;
			CSoldState state(gumballMachineMock);
			state.Dispense();
			Assert::AreEqual("", out);
			Assert::IsTrue(gumballMachineMock.noQuarterStateSet);
			Assert::IsFalse(gumballMachineMock.soldOutStateSet);
		}
	};
}