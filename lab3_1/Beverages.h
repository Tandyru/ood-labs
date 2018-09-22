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

template<typename T1, typename T2>
T2 MapEnum(const std::pair<T1, T2> map[], T1 value)
{
	auto size = sizeof(map);
	for (decltype(size) idx = 0; idx < size; idx++)
	{
		auto& item = map[idx];
		if (item.first == value)
		{
			return item.second;
		}
	}
	throw std::exception("Invalid enum value");
}

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
	enum class TeaSort
	{
		Black,
		White,
		Green, 
		Oolong
	};
	CTea(TeaSort teaSort)
		:CBeverage(GetDescription(teaSort))
	{
	}

	double GetCost() const override 
	{
		return 30; 
	}
private:
	static std::string GetDescription(TeaSort teaSort)
	{
		static const std::pair<TeaSort, const char*> map[] = {
			{ TeaSort::Black, "Black Tea" },
			{ TeaSort::White, "White Tea" },
			{ TeaSort::Green, "Green Tea" },
			{ TeaSort::Oolong, "Oolong Tea" },
		};
		return MapEnum(map, teaSort);
	}
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	enum class PortionSize
	{
		Small,
		Medium,
		Large
	};

	CMilkshake(PortionSize portionSize)
		: CBeverage(GetDescription(portionSize))
		, m_portionSize(portionSize)
	{}

	double GetCost() const override
	{
		static const std::pair<PortionSize, double> map[] = {
			{ PortionSize::Small, 50 },
			{ PortionSize::Medium, 60 },
			{ PortionSize::Large, 80 },
		};
		return MapEnum(map, m_portionSize);
	}

private:

	static std::string GetDescription(PortionSize portionSize)
	{
		static const std::pair<PortionSize, const char*> map[] = {
			{ PortionSize::Small, "Small Milkshake" }, 
			{ PortionSize::Medium, "Medium Milkshake" },
			{ PortionSize::Large, "Large Milkshake" },
		};
		return MapEnum(map, portionSize);
	}


private:
	PortionSize m_portionSize;
};
