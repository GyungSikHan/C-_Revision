#include <iostream>
using namespace std;

int main()
{
	int G{};
	cin >> G;

	int* P = &G;
	int* K = &G;
	int** t = &P;
	int** Q = &K;

	cout << **t << " " << **Q;
}