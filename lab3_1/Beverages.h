#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		:CBeverage(description) 
	{}

	double GetCost() const override 
	{
		return 60; 
	}
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino() 
		:CCoffee("Capuccino") 
	{}

	double GetCost() const override 
	{
		return 80; 
	}
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte() 
		:CCoffee("Latte") 
	{}

	double GetCost() const override 
	{
		return 90; 
	}
};

template<int C, class T = CCoffee>
class CDoubleCoffee : public IBeverage
{
public:
	std::string GetDescription() const override
	{
		return "Double " + m_coffee.GetDescription();
	}

	double GetCost() const override
	{
		return C;
	}

private:
	T m_coffee;
};

typedef CDoubleCoffee<130, CLatte> CDoubleLatte;
typedef CDoubleCoffee<120, CCapuccino> CDoubleCapuccino;

const auto TEA_DESCR = "Tea";

// Чай
class CTea : public CBeverage
{
public:
	CTea(const std::string& prefix = "")
		:CBeverage(prefix.empty() ? TEA_DESCR : prefix + " " + TEA_DESCR)
	{
	}

	double GetCost() const override 
	{
		return 30; 
	}
};

class CWhiteTea : public CTea
{
public:
	CWhiteTea()
		: CTea("White")
	{
	}
};

class CGreenTea : public CTea
{
public:
	CGreenTea()
		: CTea("Green")
	{
	}
};

class CBlackTea : public CTea
{
public:
	CBlackTea()
		: CTea("Black")
	{
	}
};

class COolongTea : public CTea
{
public:
	COolongTea()
		: CTea("Oolong")
	{
	}
};

const auto MILKSHAKE_DESCR = "Milkshake";

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(const std::string& prefix = "", double cost = 80)
		: CBeverage(prefix.empty() ? MILKSHAKE_DESCR : prefix + " " + MILKSHAKE_DESCR)
		, m_cost(cost)
	{}

	double GetCost() const override 
	{ 
		return m_cost; 
	}
private:
	double m_cost;
};

class CSmallMilkshake : public CMilkshake
{
public:
	CSmallMilkshake()
		: CMilkshake("Small", 50)
	{
	}
};

class CMediumMilkshake : public CMilkshake
{
public:
	CMediumMilkshake()
		: CMilkshake("Medium", 60)
	{
	}
};

class CLargeMilkshake : public CMilkshake
{
public:
	CLargeMilkshake()
		: CMilkshake("Large", 80)
	{
	}
};
