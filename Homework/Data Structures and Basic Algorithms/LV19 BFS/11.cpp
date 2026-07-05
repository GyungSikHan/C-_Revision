#include <iostream>
using namespace std;

const int length = 7;
int evid[length]{ -1,0,0,1,2,4,4 };
int timeStemp[length]{ 8,3,5,6,8,9,10};

void DFS(int idx)
{
	if (evid[idx] == -1)
	{
		cout << idx << "번index(출발)" << endl;
		return;
	}

	DFS(evid[idx]);
	cout << idx << "번index(" << timeStemp[idx] << "시)" << endl;

}

int main()
{
	int idx{};
	cin >> idx;
	DFS(idx);
}