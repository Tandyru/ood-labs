#pragma once
#include <iostream>

namespace with_dynamic_state
{

struct IState
{
	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;
	virtual std::string ToString()const = 0;
	virtual ~IState() = default;
};

struct IMultiGumballMachine
{
	virtual void ReleaseBall() = 0;
	virtual unsigned GetBallCount()const = 0;

	virtual void SetQuarterCount(unsigned count) = 0;
	virtual unsigned GetQuarterCount()const = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;

	virtual ~IMultiGumballMachine() = default;
};

class CSoldState : public IState
{
public:
	CSoldState(IMultiGumballMachine & gumballMachine)
		:m_gumballMachine(gumballMachine)
	{}
	void InsertQuarter() override
	{
		std::cout << "Please wait, we're already giving you a gumball\n";
	}
	void EjectQuarter() override
	{
		std::cout << "Sorry you already turned the crank\n";
	}
	void TurnCrank() override
	{
		std::cout << "Turning twice doesn't get you another gumball\n";
	}
	void Dispense() override
	{
		m_gumballMachine.ReleaseBall();
		if (m_gumballMachine.GetBallCount() == 0)
		{
			std::cout << "Oops, out of gumballs\n";
			if (m_gumballMachine.GetQuarterCount() == 0)
			{
				m_gumballMachine.SetSoldOutState();
			}
			else
			{
				m_gumballMachine.SetHasQuarterState();
			}
		}
		else
		{
			if (m_gumballMachine.GetQuarterCount() == 0)
			{
				m_gumballMachine.SetNoQuarterState();
			}
			else
			{
				m_gumballMachine.SetHasQuarterState();
			}
		}
	}
	std::string ToString() const override
	{
		return "delivering a gumball";
	}
private:
	IMultiGumballMachine & m_gumballMachine;
};

class CSoldOutState : public IState
{
public:
	CSoldOutState(IMultiGumballMachine & gumballMachine)
		:m_gumballMachine(gumballMachine)
	{}

	void InsertQuarter() override
	{
		std::cout << "You can't insert a quarter, the machine is sold out\n";
	}
	void EjectQuarter() override
	{
		std::cout << "You can't eject, you haven't inserted a quarter yet\n";
	}
	void TurnCrank() override
	{
		std::cout << "You turned but there's no gumballs\n";
	}
	void Dispense() override
	{
		std::cout << "No gumball dispensed\n";
	}
	std::string ToString() const override
	{
		return "sold out";
	}
private:
	IMultiGumballMachine & m_gumballMachine;
};

class CHasQuarterState : public IState
{
	const unsigned MAX_QUARTER_COUNT = 5;
public:
	CHasQuarterState(IMultiGumballMachine & gumballMachine)
		:m_gumballMachine(gumballMachine)
	{}

	void InsertQuarter() override
	{
		auto quarterCount = m_gumballMachine.GetQuarterCount();
		if (quarterCount >= MAX_QUARTER_COUNT)
		{
			std::cout << "You can't insert another quarter\n";
		}
		else
		{
			++quarterCount;
			m_gumballMachine.SetQuarterCount(quarterCount);
			std::cout << "You inserted a quarter\n";
		}
	}
	void EjectQuarter() override
	{
		std::cout << "Quarter(s) returned\n";
		m_gumballMachine.SetQuarterCount(0);
		m_gumballMachine.SetNoQuarterState();
	}
	void TurnCrank() override
	{
		std::cout << "You turned...\n";

		if (m_gumballMachine.GetBallCount() > 0)
		{
			m_gumballMachine.SetQuarterCount(m_gumballMachine.GetQuarterCount() - 1);
			m_gumballMachine.SetSoldState();
		}
	}
	void Dispense() override
	{
		std::cout << "No gumball dispensed\n";
	}
	std::string ToString() const override
	{
		return "waiting for turn of crank";
	}
private:
	IMultiGumballMachine & m_gumballMachine;
};

class CNoQuarterState : public IState
{
public:
	CNoQuarterState(IMultiGumballMachine & gumballMachine)
		: m_gumballMachine(gumballMachine)
	{}

	void InsertQuarter() override
	{
		std::cout << "You inserted a quarter\n";
		m_gumballMachine.SetQuarterCount(1);
		m_gumballMachine.SetHasQuarterState();
	}
	void EjectQuarter() override
	{
		std::cout << "You haven't inserted a quarter\n";
	}
	void TurnCrank() override
	{
		std::cout << "You turned but there's no quarter\n";
	}
	void Dispense() override
	{
		std::cout << "You need to pay first\n";
	}
	std::string ToString() const override
	{
		return "waiting for quarter";
	}
private:
	IMultiGumballMachine & m_gumballMachine;
};

class CMultiGumballMachine : private IMultiGumballMachine
{
public:
	CMultiGumballMachine(unsigned numBalls)
		: m_gumballCount(numBalls)
	{

		if (m_gumballCount > 0)
		{
			SetNoQuarterState();
		}
		else
		{
			SetSoldOutState();
		}
	}
	void EjectQuarter()
	{
		m_currentState->EjectQuarter();
	}
	void InsertQuarter()
	{
		m_currentState->InsertQuarter();
	}
	void TurnCrank()
	{
		m_currentState->TurnCrank();
		m_currentState->Dispense();
	}
	std::string ToString()const
	{
		std::stringstream ss;
		std::string suffix = (m_gumballCount != 1 ? "s" : "");
		std::string suffix2 = (m_quarterCount != 1 ? "s" : "");
		ss << R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: )" << m_gumballCount << " gumball" << suffix << " and " <<
m_quarterCount << " quarter" << suffix2 << R"(
Machine is )" << m_currentState->ToString();
		return ss.str();
	}
private:
	unsigned GetBallCount() const override
	{
		return m_gumballCount;
	}
	virtual void ReleaseBall() override
	{
		if (m_gumballCount != 0)
		{
			std::cout << "A gumball comes rolling out the slot...\n";
			--m_gumballCount;
		}
	}
	void SetQuarterCount(unsigned count) override
	{
		m_quarterCount = count;
	}
	unsigned GetQuarterCount()const override
	{
		return m_quarterCount;
	}
	void SetSoldOutState() override
	{
		m_currentState.reset(new CSoldOutState(*this));
	}
	void SetNoQuarterState() override
	{
		m_currentState.reset(new CNoQuarterState(*this));
	}
	void SetSoldState() override
	{
		m_currentState.reset(new CSoldState(*this));
	}
	void SetHasQuarterState() override
	{
		m_currentState.reset(new CHasQuarterState(*this));
	}
private:
	unsigned m_gumballCount = 0;
	unsigned m_quarterCount = 0;
	std::unique_ptr<IState> m_currentState;

};

}
