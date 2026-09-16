#include <iostream>

using namespace std;

int heap[7]{};
int Size{};
void MakHeap(int idx)
{
	if (idx == 1)
		return;

	int parent = idx / 2;
	if (heap[idx] < heap[parent])
		return;

	swap(heap[idx], heap[parent]);
	MakHeap(parent);
}

void Push(int data, int idx)
{
	heap[idx] = data;
	MakHeap(idx);
	Size++;
}

int Pop()
{
	int maxValue = heap[1];

	heap[1] = heap[Size];
	heap[Size] = 0;
	Size--;

	int curr = 1;
	while (Size != 0)
	{

		int left = curr * 2;
		int right = curr * 2 + 1;
		int large = curr;

		if (left <= Size && heap[left] > heap[large])
			large = left;
		if (right <= Size && heap[right] > heap[large])
			large = right;

		if (large == curr)
			break;

		swap(heap[curr], heap[large]);
			curr = large;
	}

	return maxValue;
}

int main()
{
	int arr[6]{ 5,2,9,1,5,6 };
	for (int i = 0; i < 6; ++i)
	{
		Push(arr[i], i + 1);
	}

	for (int i = 1; i < 7; ++i)
		cout << Pop();

}