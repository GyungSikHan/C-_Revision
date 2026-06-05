#include <iostream>
using namespace std;
class Product
{
public:
	Product(){}
	virtual ~Product(){}
	virtual void Use() = 0;
};

class ProductA : public Product
{
public:
	ProductA(){}
	void Use() override
	{
		cout << "Product A 사용" << endl;
	}
	~ProductA()override{}
};

class ProductB : public Product
{
public:
	ProductB() {}
	void Use() override
	{
		cout << "Product B 사용" << endl;
	}
	~ProductB()override {}
};

class Creator
{
public:
	Creator(): product(){}
	Creator(Product* product): product(product){}
	virtual ~Creator(){}
	virtual Product* CreateProduct() = 0;
protected:
	Product* product;
};

class ConcreteCreatorA : public Creator
{
public:
	ConcreteCreatorA(Product* product):Creator(product){}
	Product* CreateProduct() override
	{
		return product;
	}
	~ConcreteCreatorA()override{}
};

class ConcreteCreatorB : public Creator
{
public:
	ConcreteCreatorB(Product* product) :Creator(product) {}
	Product* CreateProduct() override
	{
		return product;
	}
	~ConcreteCreatorB()override {}
};

int main()
{
	ProductA productA; ProductB productB;
	ConcreteCreatorA creatorA(&productA);
	ConcreteCreatorB creatorB(&productB);
	Creator* creators[] = { &creatorA, &creatorB };
	for (int i = 0; i < 2; ++i)
	{
		Product* product = creators[i]->CreateProduct();
		product->Use();
	}
}