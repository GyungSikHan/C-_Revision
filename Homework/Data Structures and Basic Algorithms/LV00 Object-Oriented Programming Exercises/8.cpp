#include <iostream>
using namespace std;

class Product
{
public:
	Product()
		:productName{}, price(), quantity(), discountRate(), totalPrice()
	{
	}
	~Product() {}

	void SetProductInfo(const char* productName, const int price, const int quantity, const int discountRate)
	{
		strcpy_s(this->productName, sizeof(this->productName), productName);
		this->price = price;
		this->quantity = quantity;
		this->discountRate = discountRate;
	}
	void CalculationPrice()
	{
		float temp = (float)price * (float)quantity;
		totalPrice = temp - (temp /	(float)discountRate);
	}
	void Print()
	{
		cout << "Product: " << productName << " | Quantity: " << quantity << " | Discout: " << discountRate<<"%"<<endl;
		cout << "Total after discount: $" << totalPrice << endl;
	}

private:
	char productName[256];
	int price;
	int quantity;
	int discountRate;
	float totalPrice;
};
int main()
{
	Product product;
	product.SetProductInfo("pen", 2, 10, 10);
	product.CalculationPrice();
	product.Print();
}