#include <iostream>
using namespace std;

template <typename T>
class stack
{
public:
	stack() :mArr(new T[DEFAULT_SIZE]), mTop(-1) {}
	~stack()
	{
		delete[] mArr;
		mArr = nullptr;
		mTop = -1;
	}

	void push(T data)
	{
		mArr[++mTop] = data;
	}
	void pop()
	{
		if (mTop == -1)
			return;
		else
			mTop--;
	}
	T top()
	{
		if (mTop == -1)
			return -1;

		return mArr[mTop];
	}

private:
	static const size_t DEFAULT_SIZE = 30;
	T* mArr;
	int mTop;
};

int main()
{
	stack<int> st;
	st.push(3);
	st.push(5);
	st.push(4);

	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
}