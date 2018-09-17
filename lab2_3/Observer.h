#pragma once

#include <set>
#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>

/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer, int priority) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;
	struct ObserverData 
	{
		ObserverType *observer;
		int priority;

		ObserverData(ObserverType *observer, int priority)
			: observer(observer)
			, priority(priority)
		{
		}

		bool operator <(const ObserverData& another) const
		{
			return observer < another.observer;
		}
	};
	using Observers = std::set<ObserverData>;
	using ObserversArray = std::vector<ObserverData>;

	void RegisterObserver(ObserverType & observer, int priority) override
	{
		ObserverType *obs = &observer;
		m_observers.insert(ObserverData(obs, priority));
		++m_observersVersion;
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		Observers notifiedObservers;
		auto observers = sortObsevers(m_observers);
		ObserversArray::iterator it = observers.begin();
		while (it != observers.end())
		{
			auto& observer = *it;
			int observersVersion = m_observersVersion;
			observer.observer->Update(data);
			notifiedObservers.insert(observer);
			if (observersVersion != m_observersVersion)
			{
				observers.clear();
				auto nonsortedObservers = m_observers;
				std::set_difference(m_observers.begin(), m_observers.end(),
					notifiedObservers.begin(), notifiedObservers.end(),
					std::inserter(nonsortedObservers, nonsortedObservers.begin()));
				observers = sortObsevers(m_observers);
				it = observers.begin();
			}
			else
			{
				it++;
			}
		}
	}

	void RemoveObserver(ObserverType & observer) override
	{
		m_observers.erase(ObserverData(&observer, 0));
		++m_observersVersion;
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	static ObserversArray sortObsevers(const Observers& observers)
	{
		ObserversArray result;
		std::copy(observers.begin(), observers.end(), std::back_inserter(result));
		std::sort(result.begin(), result.end(), [](const ObserverData& obs1, const ObserverData& obs2) {
			return obs1.priority > obs2.priority;
		});
		return result;
	}

private:
	Observers m_observers;
	int m_observersVersion = 0;
};
