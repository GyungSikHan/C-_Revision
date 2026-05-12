#include <iostream>
using  namespace  std;

class CoffeeMachine
{
public:
	CoffeeMachine()
		:espresso(),wather(),suger()
	{}
	CoffeeMachine(const int espresso, const int wather, const int suger)
		:espresso(espresso),wather(wather),suger(suger)
	{}
	~CoffeeMachine(){}

	bool CheckSource(int source, int sub)
	{
		if (source <= 0)
			return false;
		if (source - sub < 0)
			return false;
		return true;
	}
	void DrinkEspresso()
	{
		if (!CheckSource(espresso, 1))
		{
			cout << "Espresso shortage" << endl;
			return;
		}
		if (!CheckSource(wather, 1))
		{
			cout << "Wather shortage" << endl;
			return;
		}
		espresso--;
		wather--;
	}
	void DrinkAmericano()
	{
		if (!CheckSource(espresso ,1))
		{
			cout << "Espresso shortage" << endl;
			return;
		}
		if (!CheckSource(wather, 2))
		{
			cout << "Wather shortage" << endl;
			return;
		}

		espresso--;
		wather -= 2;
	}
	void DrinkSugerCoffee()
	{
		if (!CheckSource(espresso, 1))
		{
			cout << "Espresso shortage" << endl;
			return;
		}
		if (!CheckSource(wather, 2))
		{
			cout << "Wather shortage" << endl;
			return;
		}
		if (!CheckSource(suger, 1))
		{
			cout << "suger shortage" << endl;
			return;
		}
		espresso--;
		wather -= 2;
		suger--;
	}

	void Show()
	{
		cout << "-----재고 조사-----" << endl;
		cout << "남은 espresson: " << espresso << endl;
		cout << "남은 wather: " << wather << endl;
		cout << "남은 suger: " << suger << endl;
		cout << endl;
	}

private:
	int espresso;
	int wather;
	int suger;
};

int main()
{
	CoffeeMachine java(5, 10, 3);
	java.DrinkEspresso();
	java.Show();
	java.DrinkAmericano();
	java.Show();
	java.DrinkSugerCoffee();
	java.Show();
}