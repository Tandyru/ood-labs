﻿#include "Beverages.h"
#include "Condiments.h"

#include <iostream>
#include <string>
#include <functional>
#include "libcc_optional.hh"

using namespace std;
using namespace sdl2pp_libcpp_optional;

/*
Функциональный объект, создающий лимонную добавку
*/
struct MakeLemon
{
	MakeLemon(unsigned quantity)
		:m_quantity(quantity)
	{}

	auto operator()(IBeveragePtr && beverage)const
	{
		return make_unique<CLemon>(move(beverage), m_quantity); 
	}
private:
	unsigned m_quantity;
};

/*
Функция, возвращающая функцию, создающую коричную добавку
*/
function<IBeveragePtr(IBeveragePtr &&)> MakeCinnamon()
{
	return [] (IBeveragePtr && b) {
		return make_unique<CCinnamon>(move(b));
	};
}

/*
Возвращает функцию, декорирующую напиток определенной добавкой

Параметры шаблона: 
	Condiment - класс добавки, конструктор которого в качестве первого аргумента
				принимает IBeveragePtr&& оборачиваемого напитка
	Args - список типов прочих параметров конструктора (возможно, пустой)
*/
template <typename Condiment, typename... Args>
auto MakeCondiment(const Args&...args)
{
	// Возвращаем функцию, декорирующую напиток, переданный ей в качестве аргумента
	// Дополнительные аргументы декоратора, захваченные лямбда-функцией, передаются
	// конструктору декоратора через make_unique
	return [=](auto && b) {
		// Функции make_unique передаем b вместе со списком аргументов внешней функции
		return make_unique<Condiment>(forward<decltype(b)>(b), args...);
	};
}

/*
Перегруженная версия оператора <<, которая предоставляет нам синтаксический сахар
для декорирования компонента

Позволяет создать цепочку оборачивающих напиток декораторов следующим образом:
auto beverage = make_unique<CConcreteBeverage>(a, b, c)
					<< MakeCondimentA(d, e, f)
					<< MakeCondimentB(g, h);

Функциональные объекты MakeCondiment* запоминают аргументы, необходимые для создания
дополнения, и возвращают фабричную функцию, принимающую оборачиваемый напиток, которая
при своем вызове создаст нужный объект Condiment, передав ему запомненные аргументы.
Использование:
	auto beverage = 
		make_unique<CConcreteBeverage>(a, b, c)
		<< MakeCondimentA(d, e, f)
		<< MakeCondimentB(g, h);
или даже так:
	auto beverage = 
		make_unique<CConcreteBeverage>
		<< MakeCondiment<CondimentA>(d, e, f)
		<< MakeCondiment<CondimentB>(g, h);
В последнем случае нет необходимости писать вручную реализации MakeCondimentA и MakeCondimentB, т.к.
необходимую реализацию сгенерирует компилятор

Классический способ оборачивания выглядел бы так:
	auto baseBeverage = make_unique<CConcretedBeverage>(a, b, c);
	auto wrappedWithCondimentA = make_unique<CCondimentA>(move(baseBeverage), d, e, f);
	auto beverage = make_unique<CCondimentB>(move(wrappedWithCondimentA), g, h);
либо так:
	auto beverage = make_unique<CCondimentB>(
						make_unique<CCondimentA>(
							make_unique<CConcreteBeverage>(a, b, c), // Напиток
							d, e, f	// доп. параметы CondimentA
						),
						g, h		// доп. параметры CondimentB
					);

unique_ptr<CLemon> operator << (IBeveragePtr && lhs, const MakeLemon & factory)
{
	return factory(move(lhs));
}
unique_ptr<CCinnamon> operator << (IBeveragePtr && lhs, const MakeCinnamon & factory)
{
	return factory(move(lhs));
}
*/
template <typename Component, typename Decorator>
auto operator << (Component && component, const Decorator & decorate)
{
	return decorate(forward<Component>(component));
}

unique_ptr<IBeverage> AskUserForCoffeeType()
{
	cout << "1 - plain coffee, 2 - latte, 3 - double latte, 4 - capuccino, 5 - double capuccino\n";
	int coffeeChoice;
	cin >> coffeeChoice;
	switch (coffeeChoice)
	{
	case 1:
		return make_unique<CCoffee>();
	case 2:
		return make_unique<CLatte>();
	case 3:
		return make_unique<CDoubleLatte>();
	case 4:
		return make_unique<CCapuccino>();
	case 5:
		return make_unique<CDoubleCapuccino>();
	default:
		return unique_ptr<IBeverage>();
	}
}

unique_ptr<IBeverage> AskUserForTeaType()
{
	cout << "1 - black, 2 - green, 3 - white, 4 - oolong\n";
	int teaChoice;
	cin >> teaChoice;
	using Sort = CTea::TeaSort;
	Sort sort;
	switch (teaChoice)
	{
	case 1:
		sort = Sort::Black;
		break;
	case 2:
		sort = Sort::Green;
		break;
	case 3:
		sort = Sort::White;
		break;
	case 4:
		sort = Sort::Oolong;
		break;
	default:
		return unique_ptr<IBeverage>();
	}
	return make_unique<CTea>(sort);
}

unique_ptr<IBeverage> AskUserForMilkshakeType()
{
	cout << "1 - small portion, 2 - medium portion, 3 - large portion\n";
	int sizeChoice;
	cin >> sizeChoice;
	using PortionSize = CMilkshake::PortionSize;
	PortionSize portionSize;
	switch (sizeChoice)
	{
	case 1:
		portionSize = PortionSize::Small;
		break;
	case 2:
		portionSize = PortionSize::Medium;
		break;
	case 3:
		portionSize = PortionSize::Large;
		break;
	default:
		return unique_ptr<IBeverage>();
	}
	return make_unique<CMilkshake>(portionSize);
}

unsigned AskUserForChoclateSliceCount()
{
	cout << "Choclate slice count (1-5): " << endl;
	unsigned sliceCount;
	cin >> sliceCount;
	if (sliceCount > CChocolate::MAX_SLICE_COUNT)
	{
		return 0;
	}
	return sliceCount;
}

optional<CLiquor::Type> AskUserForLiquorType()
{
	cout << "1 - Nut Liquor, 2 - Choclate Liquor" << endl;
	int type;
	cin >> type;
	switch (type)
	{
	case 1:
		return CLiquor::Type::Nut;
	case 2:
		return CLiquor::Type::Chocolate;
	}
	return optional<CLiquor::Type>();
}

unique_ptr<IBeverage> AskUserForCondiment(unique_ptr<IBeverage> && beverage, bool &checkout)
{
	cout << "1 - Lemon, 2 - Cinnamon, 3 - Cream, 4 - Chocolate, 5 - Liquor, 0 - Checkout" << endl;
	int condimentChoice;
	cin >> condimentChoice;

	switch (condimentChoice)
	{
	case 1:
		return move(beverage) << MakeCondiment<CLemon>(2);
	case 2:
		return move(beverage) << MakeCondiment<CCinnamon>();
	case 3:
		return move(beverage) << MakeCondiment<CCream>();
	case 4:
	{
		unsigned sliceCount = AskUserForChoclateSliceCount();
		if (sliceCount > 0)
		{
			return move(beverage) << MakeCondiment<CChocolate>(sliceCount);
		}
		break;
	}
	case 5:
	{
		optional<CLiquor::Type> liquorType = AskUserForLiquorType();
		if (liquorType)
		{
			return move(beverage) << MakeCondiment<CLiquor>(*liquorType);
		}
		break;
	}
	case 0:
		checkout = true;
		break;
	}
	return move(beverage);
}

void DialogWithUser()
{
	cout << "Type 1 for coffee or 2 for tea or 3 for milkshake\n";
	int beverageChoice;
	cin >> beverageChoice;

	unique_ptr<IBeverage> beverage;

	bool coffeeChosen = false;
	if (beverageChoice == 1)
	{
		beverage = AskUserForCoffeeType();
	}
	else if (beverageChoice == 2)
	{
		beverage = AskUserForTeaType();
	}
	else if (beverageChoice == 3)
	{
		beverage = AskUserForMilkshakeType();
	}
	else
	{
		return;
	}
	if (!beverage)
	{
		return;
	}


	for (;;)
	{
		bool checkout = false;
		beverage = AskUserForCondiment(move(beverage), checkout);
		if (checkout)
		{
			break;
		}
	}



	cout << beverage->GetDescription() << ", cost: " << beverage->GetCost() << endl;
}


int main()
{
	DialogWithUser();
	cout << endl;
	{
		// Наливаем чашечку латте
		auto latte = make_unique<CLatte>();
		// добавляем корицы
		auto cinnamon = make_unique<CCinnamon>(move(latte));
		// добавляем пару долек лимона
		auto lemon = make_unique<CLemon>(move(cinnamon), 2);
		// добавляем пару кубиков льда
		auto iceCubes = make_unique<CIceCubes>(move(lemon), 2, IceCubeType::Dry);
		// добавляем 2 грамма шоколадной крошки
		auto beverage = make_unique<CChocolateCrumbs>(move(iceCubes), 2);

		// Выписываем счет покупателю
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CChocolateCrumbs>(			// Внешний слой: шоколадная крошка
				make_unique<CIceCubes>(				// | под нею - кубики льда
					make_unique<CLemon>(			// | | еще ниже лимон
						make_unique<CCinnamon>(		// | | | слоем ниже - корица
							make_unique<CLatte>()),	// | | |   в самом сердце - Латте
						2),							// | | 2 дольки лимона
					2, IceCubeType::Dry),			// | 2 кубика сухого льда
				2);									// 2 грамма шоколадной крошки

		// Выписываем счет покупателю
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	// Подробнее рассмотрим работу MakeCondiment и оператора <<
	{
		// lemon - функция, добавляющая "2 дольки лимона" к любому напитку
		auto lemon2 = MakeCondiment<CLemon>(2);
		// iceCubes - функция, добавляющая "3 кусочка льда" к любому напитку
		auto iceCubes3 = MakeCondiment<CIceCubes>(3, IceCubeType::Water);
		
		auto tea = make_unique<CTea>(CTea::TeaSort::Black);

		// декорируем чай двумя дольками лимона и тремя кусочками льда
		auto lemonIceTea = iceCubes3(lemon2(move(tea)));	
		/* Предыдущая строка выполняет те же действия, что и следующий код:
		auto lemonIceTea = 
			make_unique<CIceCubes>(
				make_unique<CLemon>(
					move(tea), 
					2), 
				2, IceCubeType::Water);
		*/
		
		auto oneMoreLemonIceTea =
			make_unique<CTea>(CTea::TeaSort::Black)	// Берем чай
			<< MakeCondiment<CLemon>(2)	// добавляем пару долек лимона
			<< MakeCondiment<CIceCubes>(3, IceCubeType::Water); // и 3 кубика льда
		/*
		Предыдущая конструкция делает то же самое, что и следующая:
		auto oneMoreLemonIceTea =
			MakeCondiment<CIceCubes>(3, IceCubeType::Water)(
				MakeCondiment<CLemon>(2)(make_unique<CTea>())
				);
		*/
	}

	// Аналог предыдущего решения с добавкой синтаксического сахара
	// обеспечиваемого операторами << и функцией MakeCondiment
	{
		auto beverage = 
			make_unique<CLatte>()							// Наливаем чашечку латте,
			<< MakeCondiment<CCinnamon>()					// оборачиваем корицей,
			<< MakeCondiment<CLemon>(2)						// добавляем пару долек лимона
			<< MakeCondiment<CIceCubes>(2, IceCubeType::Dry)// брасаем пару кубиков сухого льда
			<< MakeCondiment<CChocolateCrumbs>(2);			// посыпаем шоколадной крошкой

		// Выписываем счет покупателю
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage = 
			make_unique<CMilkshake>(CMilkshake::PortionSize::Medium)					// Наливаем молочный коктейль
			<< MakeCondiment<CSyrup>(SyrupType::Maple)	// заливаем кленовым сиропом
			<< MakeCondiment<CCoconutFlakes>(8);		// посыпаем кокосовой стружкой

		// Выписываем счет покупателю
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}
}