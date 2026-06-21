#include <iostream>
using namespace std;

template<typename T>
class Data
{
public:
	T GetData() { return data; }
	void SetData(T Data) { data = Data; }
private:
	T data;
};

int main()
{
	Data<int> intData;
	Data<float> floatData;

	intData.SetData(2);
	floatData.SetData(2.4f);

	cout << intData.GetData() << endl;
	cout << floatData.GetData() << endl;
}