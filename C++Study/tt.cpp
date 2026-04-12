#include<iostream>

using namespace std;

void Increase(int* a, int* b)
{
	*a += 1;
	*b += 1;
}

void Insert(int* a, int* b)
{
	*a = 100;
	*b = 100;
}

//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//
//	Increase(&num1, &num2);
//	cout << num1 << " " << num2 << endl;
//	Insert(&num1, &num2);
//	cout << num1 << " " << num2 << endl;
//	
//	return 0;
//}

void bbq(int* pArr)
{
	*(pArr) = 100;
	*(pArr+1) = 100;
	*(pArr+2) = 100;
	*(pArr+3) = 100;
	*(pArr+4) = 100;
	*(pArr+5) = 100;
	*(pArr+6) = 100;
	*(pArr+7) = 100;
	*(pArr+8) = 100;
	*(pArr+9) = 100;

	pArr[0] = 200;
	pArr[1] = 200;
	pArr[2] = 200;
	pArr[3] = 200;
	pArr[4] = 200;
	pArr[5] = 200;
	pArr[6] = 200;
	pArr[7] = 200;
	pArr[8] = 200;
	pArr[9] = 200;
}
//int main()
//{
//	int vec[10]{};
//	bbq(vec);
//}

//int main()
//{
//	int vect[3][3]=
//		{
//		3,4,1,
//		5,5,7,
//		8,3,2
//	};
//
//	int min = INT_MAX;
//	int max = INT_MIN;
//	int dx{}, dx2{};
//	int dy{}, dy2{};
//
//	for (int y = 0; y < 3; y++)
//	{
//		for (int x = 0; x < 3; x++)
//		{
//			if (vect[y][x] < min)
//			{
//				min = vect[y][x];
//				dy = y;
//				dx = x;
//			}
//
//			if (vect[y][x] > max)
//			{
//				max = vect[y][x];
//				dy2 = y;
//				dx2 = x;
//			}
//		}
//	}
//
//	cout << "최소값: " << min << endl;
//	cout << "y: " << dy << " x:" << dx << endl;
//	cout << endl;
//	cout << "최대값: " << max << endl;
//	cout << "y: " << dy2 << " x:" << dx2 << endl;
//	
//}

void Input(int* input)
{
	for (int i = 0; i < 3; i++)
	{
		cin >> *(input + i);
	}
}

void Process(int arr[6][2], int* input, int* count)
{
	for (int i = 0; i< 3; i++)
	{
		int cnt{};
		for (int j = 0; j< 6; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (input[i] == arr[j][k])
				{
					cnt++;
				}
			}
		}
		*(count + i) = cnt;
	}
}

void Output(int* input, int* count)
{
	for (int i = 0; i < 3; i++)
	{
		cout << input[i] << "의 갯수는 " << count[i] << "입니다." << endl;
	}
}

int main()
{
	int arr[6][2] =
		{
		4,5,6,1,3,1,
		2,1,3,6,3,6
	};
	int input[3]{};
	int count[3]{};

	Input(input);
	Process(arr, input, count);
	Output(input, count);
}