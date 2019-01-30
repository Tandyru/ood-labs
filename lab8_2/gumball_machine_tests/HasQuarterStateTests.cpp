#include "stdafx.h"
#include "../gumball_machine/MultiGumBallMachineWithDynamicallyCreatedState.h"
#include "GambleMachineMock.h"
#include "TestOutStream.h"
#include "CppUnitTest.h"

using namespace with_dynamic_state;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gumball_machine_tests
{		
	TEST_CLASS(HasQuarterStateTests)
	{
		TestOutStream out;
		CGumballMachineMock gumballMachineMock;

	public:
		
		TEST_METHOD(TestHasQuarterStateOnInsertQuarterReaction)
		{
			CHasQuarterState state(gumballMachineMock);
			state.InsertQuarter();
			Assert::AreEqual("You inserted a quarter\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}
		
		TEST_METHOD(TestHasQuarterStateOnEjectQuarterReaction)
		{
			CHasQuarterState state(gumballMachineMock);
			state.EjectQuarter();
			Assert::AreEqual("Quarter(s) returned\n", out);
			Assert::IsTrue(gumballMachineMock.noQuarterStateSet);
		}
		
		TEST_METHOD(TestHasQuarterStateOnTurnCrankReaction)
		{
			CHasQuarterState state(gumballMachineMock);
			state.TurnCrank();
			Assert::AreEqual("You turned...\n", out);
			Assert::IsTrue(gumballMachineMock.soldStateSet);
		}
		
		TEST_METHOD(TestHasQuarterStateOnDispenseReaction)
		{
			gumballMachineMock.ballCount = 2;
			CHasQuarterState state(gumballMachineMock);
			state.Dispense();
			Assert::AreEqual("No gumball dispensed\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}
	};
}