#include <iostream>
using namespace std;

class SortStrategy
{
public:
	SortStrategy(){}
	virtual ~SortStrategy(){}
	virtual void Sort(int* data, int size) = 0;
};

class BubbleSort : public SortStrategy
{
public:
	BubbleSort(){}
	~BubbleSort() override {}
	void Sort(int* data, int size) override
	{
		for (int i = 0; i < size-1; ++i)
		{
			for (int j = 0; j < size-i-1; ++j)
			{
				if (data[j] > data[j+1])
				{
					swap(data[j], data[j+1]);
				}
			}
		}
	}
};

class QuickSort : public SortStrategy
{
public:
	QuickSort() {}
	~QuickSort() override {}
	
	void Solve(int* data, int low, int high)
	{
		if (low >= high)
			return;

		int& pivot = data[low];
		int left = low + 1;
		int right = high;
		while (left <= right)
		{
			if (pivot >= data[left])
				left++;
			else if (pivot <= data[right])
				right--;
			else if (data[left]> data[right])
			{
				swap(data[left], data[right]);
				left++;
				right--;
			}
		}
		if (pivot > data[right])
			swap(pivot, data[right]);

		Solve(data,low, right-1);
		Solve(data,right+1, high);
	}
	void Sort(int* data, int size) override
	{
		Solve(data, 0,size-1);
	}
};

class Sorter
{
public:
	Sorter(SortStrategy* node)
	{
		SetStrategy(node);
	}
	void SetStrategy(SortStrategy* node)
	{
		strategys = node;
		memcpy(data, temp, sizeof(data));
	}
	void PerformSort()
	{
		strategys->Sort(data, 10);
		Print();
	}
	virtual void Print()
	{
		for (int i = 0; i < 10; ++i)
			cout << data[i] << " ";
		cout << endl;
	}
public:
	SortStrategy* strategys;
	int data[10]{ 1,0,3,8,9,2,6,4,5,7 };
	int temp[10]{ 1,0,3,8,9,2,6,4,5,7 };
};

int main()
{
	BubbleSort bubble; QuickSort quick;
	Sorter sorter(&bubble);
	sorter.PerformSort();  // BubbleSort 사용
	sorter.SetStrategy(&quick);
	sorter.PerformSort();  // QuickSort 사용
}