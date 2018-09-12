#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

using FlyBehaviorF = function<void(void)>;
FlyBehaviorF flyWithWingsFactory()
{
	shared_ptr<int> counter = make_shared<int>(0);
	return [counter]() {
		(*counter)++;
		cout << "I'm flying with wings!! (" << *counter << ")" << endl;
	};
}

using QuackBehaviorF = function<void(void)>;

QuackBehaviorF quackBehavior = [] {
	cout << "Quack Quack!!!" << endl;
};

QuackBehaviorF squeakBehavior = [] {
	cout << "Squeek!!!" << endl;
};

using DanceBehaviorF = function<void(void)>;

DanceBehaviorF waltzBehavior = [] {
	cout << "I'm dancing the waltz!!!" << endl;
};

DanceBehaviorF minuetBehavior = [] {
	cout << "I'm dancing the minuet!!!" << endl;
};

class Duck
{
public:
	Duck(const FlyBehaviorF& flyBehavior,
		const QuackBehaviorF& quackBehavior,
		const DanceBehaviorF& danceBehavior
	)
		: m_quackBehavior(quackBehavior)
		, m_danceBehavior(danceBehavior)
	{
		SetFlyBehavior(move(flyBehavior));
	}
	void Quack() const
	{
		if (m_quackBehavior)
		{
			m_quackBehavior();
		}
	}
	void Swim()
	{
		cout << "I'm swimming" << endl;
	}
	void Fly()
	{
		if (m_flyBehavior)
		{
			m_flyBehavior();
		}
	}
	void Dance()
	{
		if (m_danceBehavior)
		{
			m_danceBehavior();
		}
	}
	void SetFlyBehavior(const FlyBehaviorF& flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	}
	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	FlyBehaviorF m_flyBehavior;
	QuackBehaviorF m_quackBehavior;
	DanceBehaviorF m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(flyWithWingsFactory(), quackBehavior, waltzBehavior)
	{
	}

	void Display() const override
	{
		cout << "I'm mallard duck" << endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(flyWithWingsFactory(), quackBehavior, minuetBehavior)
	{
	}
	void Display() const override
	{
		cout << "I'm redhead duck" << endl;
	}
};

class DecoyDuck : public Duck
{
public:
	DecoyDuck()
		: Duck(FlyBehaviorF(), QuackBehaviorF(), DanceBehaviorF())
	{
	}
	void Display() const override
	{
		cout << "I'm decoy duck" << endl;
	}
};
class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(FlyBehaviorF(), squeakBehavior, DanceBehaviorF())
	{
	}
	void Display() const override
	{
		cout << "I'm rubber duck" << endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(FlyBehaviorF(), quackBehavior, DanceBehaviorF())
	{
	}
	void Display() const override
	{
		cout << "I'm model duck" << endl;
	}
};

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck& duck)
{
	DrawDuck(duck);
	duck.Quack();
	duck.Fly();
	duck.Dance();
	cout << endl;
}

void main()
{
	MallardDuck mallarDuck;
	PlayWithDuck(mallarDuck);
	PlayWithDuck(mallarDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehavior(flyWithWingsFactory());
	PlayWithDuck(modelDuck);
}
