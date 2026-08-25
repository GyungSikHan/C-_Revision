#include <iostream>
#include <variant>

int maxHeap[256]{};
int heapSize{};

void push(int value)
{
	heapSize++;
	maxHeap[heapSize] = value;

	int currentIndex = heapSize;

	while (currentIndex > 1)
	{
		int parentIndex = currentIndex / 2;

		if (maxHeap[parentIndex] >= maxHeap[currentIndex])
			break;

		std::swap(maxHeap[parentIndex], maxHeap[currentIndex]);
		currentIndex = parentIndex;
	}
}

int pop()
{
	int maxValue = maxHeap[1];

	maxHeap[1] = maxHeap[heapSize];
	maxHeap[heapSize] = 0;
	heapSize--;

	int currentIndex = 1;

	while (true)
	{
		int leftChildIndex = currentIndex * 2;
		int rightCHildIndex = currentIndex * 2 + 1;
		int largestIndex = currentIndex;

		if (leftChildIndex <= heapSize && maxHeap[leftChildIndex] > maxHeap[largestIndex])
		{
			largestIndex = leftChildIndex;
		}
		if (rightCHildIndex <= heapSize && maxHeap[rightCHildIndex] > maxHeap[largestIndex])
		{
			largestIndex = rightCHildIndex;
		}

		if (largestIndex == currentIndex)
			break;

		std::swap(maxHeap[largestIndex], maxHeap[currentIndex]);
		currentIndex = largestIndex;
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

	std::cout << pop() << std::endl;
	std::cout << pop() << std::endl;
	std::cout << pop() << std::endl;
	std::cout << pop() << std::endl;
	std::cout << pop() << std::endl;
	std::cout << pop() << std::endl;
}