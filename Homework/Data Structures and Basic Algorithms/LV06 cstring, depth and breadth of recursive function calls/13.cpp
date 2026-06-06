#include <iostream>
using namespace std;

void Print(int data,int cnt)
{
	if (cnt == 0)
		return;
	cout << data << " ";
	Print(data, cnt - 1);
}

int main()
{
	int vect[8]{};
	for (int i = 0; i < 8; ++i)
		cin >> vect[i];
	
	int bucket[10]{};

	for (int i = 0; i < 8; ++i)
		bucket[vect[i]]++;

	for (int i = 0; i < 10; ++i)
	{
		if (bucket[i] != 0)
			Print(i, bucket[i]);
	}

}