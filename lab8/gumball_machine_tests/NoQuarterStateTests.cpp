#include "stdafx.h"
#include "../gumball_machine/GumBallMachineWithDynamicallyCreatedState.h"
#include "GambleMachineMock.h"
#include "TestOutStream.h"
#include "CppUnitTest.h"

using namespace with_dynamic_state;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gumball_machine_tests
{		
	TEST_CLASS(NoQuarterStateTests)
	{
		TestOutStream out;
		CGumballMachineMock gumballMachineMock;

	public:
		
		TEST_METHOD(TestNoQuarterStateOnInsertQuarterReaction)
		{
			CNoQuarterState state(gumballMachineMock);
			state.InsertQuarter();
			Assert::AreEqual("You inserted a quarter\n", out);
			Assert::IsTrue(gumballMachineMock.hasQuarterStateSet);
		}
		
		TEST_METHOD(TestNoQuarterStateOnEjectQuarterReaction)
		{
			CNoQuarterState state(gumballMachineMock);
			state.EjectQuarter();
			Assert::AreEqual("You haven't inserted a quarter\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}
		
		TEST_METHOD(TestNoQuarterStateOnTurnCrankReaction)
		{
			CNoQuarterState state(gumballMachineMock);
			state.TurnCrank();
			Assert::AreEqual("You turned but there's no quarter\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}
		
		TEST_METHOD(TestNoQuarterStateOnDispenseReaction)
		{
			gumballMachineMock.ballCount = 2;
			CNoQuarterState state(gumballMachineMock);
			state.Dispense();
			Assert::AreEqual("You need to pay first\n", out);
			Assert::IsFalse(gumballMachineMock.IsStateChanged());
		}
	};
}