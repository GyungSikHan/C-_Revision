#include <iostream>

using namespace std;
int maxHeap[256]{};
int heapSize = 0;

void push(int value)
{
	heapSize++;
	maxHeap[heapSize] = value;

	int currIndex = heapSize;

	while (currIndex > 1)
	{
		int parentIndex = currIndex / 2;
		if (maxHeap[parentIndex] >= maxHeap[currIndex])
			break;

		swap(maxHeap[parentIndex], maxHeap[currIndex]);
		currIndex = parentIndex;
	}
}

int pop()
{
	int maxValue = maxHeap[1];
	maxHeap[1] = maxHeap[heapSize];
	maxHeap[heapSize] = 0;
	heapSize--;

	int currIndex = 1;

	while (true)
	{
		int leftChildIndex = currIndex * 2;
		int rightChildIndex = currIndex * 2+1;
		int largestIndex = currIndex;

		if (leftChildIndex <= heapSize && maxHeap[leftChildIndex] > maxHeap[largestIndex])
			largestIndex = leftChildIndex;

		if (rightChildIndex <= heapSize && maxHeap[rightChildIndex] > maxHeap[largestIndex])
			largestIndex = rightChildIndex;

		if (largestIndex == currIndex)
			break;

		swap(maxHeap[currIndex], maxHeap[largestIndex]);
		currIndex = largestIndex;
	}

	return maxValue;
}

int main()
{
	push(3);
	push(5);
	push(2);
	push(4);
	push(1);
	push(6);

	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
}