#include <iostream>
using namespace  std;

int arr[5][5] = {
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25}
};

int GetValue(int baseY, int baseX, int offsetY, int offsetX)
{
	int targetY = baseY + offsetY;
	int targetX = baseX + offsetX;

	if (targetY >= 0 && targetY < 5 &&
		targetX >= 0 && targetX < 5)
		return arr[targetY][targetX];

	return -1;
}

int main()
{
	int value = GetValue(2, 2, 1, 1);
	if (value != -1)
		cout << "value at (2,2) + (1,1) " << value << endl;
	else
		cout << "Out of Bounds!" << endl;
}