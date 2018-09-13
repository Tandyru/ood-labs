﻿#pragma once

#include <set>
#include <functional>

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
	virtual void RegisterObserver(IObserver<T> & observer) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer) override
	{
		m_observers.insert(&observer);
		++m_observersVersion;
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		//std::set<ObserverType *> m_notifiedObservers;
		std::set<ObserverType *> observers(m_observers);
		for (auto & observer : observers)
		{
			observersVersion = m_observersVersion;
			observer->Update(data);
			if (observersVersion != m_observersVersion)
			{
				// ??
			}
		}
	}

	void RemoveObserver(ObserverType & observer) override
	{
		m_observers.erase(&observer);
		++m_observersVersion;
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	std::set<ObserverType *> m_observers;
	int m_observersVersion = 0;
};
