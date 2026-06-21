#include <iostream>
using namespace std;

template <typename  T>
class vector
{
public:
	vector()
	: mSize(0), mCapacity(1)
	{
		mData = new T[mCapacity]{};
	}
	~vector()
	{
		delete[] mData;
		mData = nullptr;
	}

	void push_back(T value)
	{
		if (mCapacity <= mSize)
			reserve(mCapacity+1);
		
		mData[mSize++] = value;
	}
	void clear()
	{
		if (mData)
		{
			delete[] mData;
			mSize = 0;
			mCapacity = 1;
			mData = new T[mCapacity]{};
		}
	}
	void resize(int newSize)
	{
		T* temp = new T[newSize];
		memset(temp, 0, newSize);
		int copySize = (mSize < newSize ? mSize : newSize);
	
		for (int i = 0; i < mSize; ++i)
			temp[i] = mData[i];

		for (int i = copySize; i < newSize; ++i)
			temp[i] = mData[i];

		delete[] mData;
		mData = temp;
		mSize = newSize;
		if (mCapacity < newSize)
			mCapacity = newSize;
	}
	void reserve(int size)
	{
		mCapacity = size;
		T* temp = new T[mCapacity]{};
		memset(temp, 0, mCapacity);
		memcpy(temp, mData, mCapacity);

		delete[] mData;
		mData = temp;
	}
private:
	T* mData;
	int mSize;
	int mCapacity;
};

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.clear();

	v.resize(5);
	v.reserve(10);
}