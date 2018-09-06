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

struct IDanceBehavior
{
	virtual ~IDanceBehavior() {}
	virtual void Dance() = 0;
};

class ValseDanceBehavior : public IDanceBehavior
{
public:
	void Dance() override
	{
		cout << "I'm dancing the valse!!!" << endl;
	}
};

class MinuetDanceBehavior : public IDanceBehavior
{
	void Dance() override
	{
		cout << "I'm dancing the minuet!!!" << endl;
	}
};

class NoDanceBehavior : public IDanceBehavior
{
	void Dance() override {}
};

class Duck
{
public:
	Duck(const FlyBehaviorF& flyBehavior,
		const QuackBehaviorF& quackBehavior,
		unique_ptr<IDanceBehavior>&& danceBehavior
	)
		: m_quackBehavior(quackBehavior)
		, m_danceBehavior(move(danceBehavior))
	{
		assert(m_danceBehavior);
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
		m_danceBehavior->Dance();
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
	unique_ptr<IDanceBehavior> m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(flyWithWingsFactory(), quackBehavior, make_unique<ValseDanceBehavior>())
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
		: Duck(flyWithWingsFactory(), quackBehavior, make_unique<MinuetDanceBehavior>())
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
		: Duck(FlyBehaviorF(), QuackBehaviorF(), make_unique<NoDanceBehavior>())
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
		: Duck(FlyBehaviorF(), squeakBehavior, make_unique<NoDanceBehavior>())
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
		: Duck(FlyBehaviorF(), quackBehavior, make_unique<NoDanceBehavior>())
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
