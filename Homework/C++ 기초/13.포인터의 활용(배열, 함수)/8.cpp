#include <iostream>
using namespace std;

int main()
{
	struct PROFILE
	{
		char name[CHAR_MAX];
		int age;
		int weight;
	};

	PROFILE int1, int2;

	cin >> int1.name;
	cin >> int1.age;
	cin >> int1.weight;

	cin >> int2.name;
	cin >> int2.age;
	cin >> int2.weight;

	int averAge = (int1.age + int2.age) / 2;
	int averWeight = (int1.weight+ int2.weight) / 2;
	cout << int1.name << " & " << int2.name << endl;
	cout << "평균" << averAge << "세" << endl;
	cout << "평균" << averWeight << "kg" << endl;

}