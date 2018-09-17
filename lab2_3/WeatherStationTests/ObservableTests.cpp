#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Observer.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WeatherStationTests
{		
	TEST_CLASS(CObservableTest)
	{
	public:
		TEST_METHOD(TestRemoveObserverOnUpdate)
		{
			class CObservableInt : public CObservable<int>
			{
				int GetChangedData()const override
				{
					return 0;
				}
			};

			class CTestObserver : IObserver<int>
			{
			public:
				CTestObserver(CObservableInt& observable)
					: m_observable(observable)
				{
					m_observable.RegisterObserver(*this, 0);
				}

				void Update(int const& data) override
				{
					m_observable.RemoveObserver(*this);
				}

				CObservableInt& m_observable;
			};

			CObservableInt observable;
			CTestObserver observer(observable);

			observable.NotifyObservers();
		}

		TEST_METHOD(TestPriorities)
		{
			class CObservableInt : public CObservable<int>
			{
				int GetChangedData()const override
				{
					return 0;
				}
			};

			class CTestObserver : IObserver<int>
			{
			public:
				using OnNotifiedCallback = std::function<void(int)>;
				CTestObserver(CObservableInt& observable, int priority, const OnNotifiedCallback& onNotified)
					: m_observable(observable)
					, m_priority(priority)
					, m_onNotified(onNotified)
				{
					m_observable.RegisterObserver(*this, priority);
				}

				void Update(int const& data) override
				{
					m_onNotified(m_priority);
				}

				CObservableInt& m_observable;
				int m_priority;
			private:
				OnNotifiedCallback m_onNotified;
			};

			CObservableInt observable;
			std::vector<int> calls;
			auto onNotified = [&calls](int prioity) {
				calls.push_back(prioity);
			};
			CTestObserver observer(observable, 1, onNotified);
			CTestObserver observer2(observable, 3, onNotified);
			CTestObserver observer3(observable, 2, onNotified);

			observable.NotifyObservers();

			std::vector<int> expectedCalls = { 3, 2, 1 };
			Assert::AreEqual(expectedCalls.size(), calls.size());
			for (size_t i = 0; i < calls.size(); i++)
			{
				Assert::AreEqual(calls[i], expectedCalls[i]);
			}
		}

	};
}