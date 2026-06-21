#include <iostream>

using namespace std;

template <typename T>
class queue
{
public:
	queue():mArr(new T[30]), mTopIndex(-1){}
	~queue()
	{
		delete[] mArr;
		mArr = nullptr;
		mTopIndex = -1;
	}
	void push(T data)
	{
		mArr[++mTopIndex] = data;
	}
	void pop()
	{
		if (mTopIndex < 0)
			return;
		mArr[mTopIndex--] = 0;
	}

	T top()
	{
		if (mTopIndex < 0)
			return -1;

		return mArr[mTopIndex];
	}

private:
	static const int INIT = 30;
	T* mArr;
	int mTopIndex;
};

int main()
{
	queue<int> qu;
	qu.push(10);
	qu.push(20);

	cout << "Top: " <<qu.top() << endl;
	qu.pop();
	cout << "Top: " <<qu.top() << endl;
	qu.pop();
	cout << "Top: " <<qu.top() << endl;

}