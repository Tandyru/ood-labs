﻿#pragma once

#include <iostream>
#include <sstream>

namespace naive
{
class CMultiGumballMachine
{
public:
	enum class State
	{
		SoldOut,		// Жвачка закончилась
		NoQuarter,		// Нет монетки
		HasQuarter,		// Есть монетка
		Sold,			// Монетка выдана
	};

	const unsigned MAX_QUARTER_COUNT = 5;

	CMultiGumballMachine(unsigned count)
		: m_gumballCount(count)
		, m_quaterCount(0)
		, m_state(count > 0 ? State::NoQuarter : State::SoldOut)
	{
	}

	void InsertQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You can't insert a quarter, the machine is sold out\n";
			break;
		case State::NoQuarter:
			++m_quaterCount;
			cout << "You inserted a quarter\n";
			m_state = State::HasQuarter;
			break;
		case State::HasQuarter:
			if (m_quaterCount < MAX_QUARTER_COUNT)
			{
				++m_quaterCount;
				cout << "You inserted a quarter\n";
			}
			else 
			{
				cout << "You can't insert another quarter\n";
			}
			break;
		case State::Sold:
			cout << "Please wait, we're already giving you a gumball\n";
			break;
		}
	}

	void EjectQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::HasQuarter:
			cout << "Quarter(s) returned\n";
			m_state = State::NoQuarter;
			m_quaterCount = 0;
			break;
		case State::NoQuarter:
			cout << "You haven't inserted a quarter\n";
			break;
		case State::Sold:
			cout << "Sorry you already turned the crank\n";
			break;
		case State::SoldOut:
			cout << "You can't eject, you haven't inserted a quarter yet\n";
			break;
		}
	}

	void TurnCrank()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You turned but there's no gumballs\n";
			break;
		case State::NoQuarter:
			cout << "You turned but there's no quarter\n";
			break;
		case State::HasQuarter:
			cout << "You turned...\n";
			if (m_gumballCount > 0) 
			{
				m_state = State::Sold;
				--m_quaterCount;
				Dispense();
			}
			break;
		case State::Sold:
			cout << "Turning twice doesn't get you another gumball\n";
			break;
		}
	}

	void Refill(unsigned numBalls)
	{
		m_gumballCount = numBalls;
		m_state = numBalls > 0 ? State::NoQuarter : State::SoldOut;
	}

	std::string ToString()const
	{
		std::string state =
			(m_state == State::SoldOut)    ? "sold out" :
			(m_state == State::NoQuarter)  ? "waiting for quarter" :
			(m_state == State::HasQuarter) ? "waiting for turn of crank"
			                               : "delivering a gumball";
		std::stringstream ss;
		std::string suffix = (m_gumballCount != 1 ? "s" : "");
		std::string suffix2 = (m_quaterCount != 1 ? "s" : "");
		ss << R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016
Inventory: )" << m_gumballCount << " gumball" << suffix << " and "<< 
m_quaterCount << " quarter" << suffix2 << R"(
Machine is )" << state;
		return ss.str();
	}

private:
	void Dispense()
	{
		using namespace std;
		switch (m_state)
		{
		case State::Sold:
			cout << "A gumball comes rolling out the slot\n";
			--m_gumballCount;
			if (m_gumballCount == 0)
			{
				cout << "Oops, out of gumballs\n";
				m_state = State::SoldOut;
			}
			else
			{
				if (m_quaterCount == 0)
				{
					m_state = State::NoQuarter;
				}
				else
				{
					m_state = State::HasQuarter;
				}
			}
			break;
		case State::NoQuarter:
			cout << "You need to pay first\n";
			break;
		case State::SoldOut:
		case State::HasQuarter:
			cout << "No gumball dispensed\n";
			break;
		}
	}

	unsigned m_gumballCount;	// Количество шариков
	unsigned m_quaterCount;
	State m_state = State::SoldOut;
};
}