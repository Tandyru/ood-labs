#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Observer.h"

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
					m_observable.RegisterObserver(*this);
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

	};
}