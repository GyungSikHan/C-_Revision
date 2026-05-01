#include <iostream>
#include <iso646.h>

using namespace std;

class Product
{
public:
	Product(): name{}, price(), num(), discountRate(), discountPrice(){}
	Product(const char* name, const int price, const int num, const int discountRate)
		:price(price), num(num), discountRate(discountRate)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		discountPrice = CarculDiscount();
	}
	~Product(){}

	float GetPrice()const { return price; }
	float GetDiscountPrice()const { return discountPrice; }

	float CarculDiscount()
	{
		if (discountRate == 0)
		{
			return (float)(price * num);
		}

		float total = (float)(price * num);
		float temp = (float)(price * num) / (float)discountRate;
		return total - temp;
	}

	void Print()
	{
		cout << "- " << name << ": $" << price << " x " << num << " "
			"(Discount " << discountRate << "%) -> $" << discountPrice<<endl;
	}

private:
	char name[256];
	float price;
	float discountPrice;
	int num;
	int discountRate;

};

class Order
{
public:
	Order(): name{}, days{}, items{}, size(), Total(){}
	~Order(){}

	void SetName(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	void SetOrderDays(const char* days)
	{
		strcpy_s(this->days, sizeof(this->days), days);
	}
	void AddItem(Product* item)
	{
		items[size] = *item;
		Total += items[size].GetDiscountPrice();
		size++;
	}

	void Print()
	{
		cout << "Order by: " << name << " | Date: " << days << endl;
		cout << "Items: " << endl;
		
		
		for (int i = 0; i < size; ++i)
		{
			items[i].Print();
		}
		cout << "Total: $" << Total << endl;
	}

private:
	char name[256];
	char days[256];
	Product items[100];
	int size;
	float Total;
};

int main()
{
	Product item = Product("keyboard",50, 1, 0);
	Product item2 = Product("Mouse",20, 2, 10);

	Order order;
	order.SetName("Alice");
	order.SetOrderDays("2024-05-18");
	order.AddItem(&item);
	order.AddItem(&item2);

	order.Print();
}