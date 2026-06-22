#pragma once
#include "../LV14 Dynamic Allocation, Linked List Functions/list.h"

namespace Homework
{
	template <typename T>
	class vector
	{
	public:
		vector():mSize(-1), mCapacity(-1), mArr(){}
		vector(size_t size, T data = 0)
			:mSize(size),mCapacity(size), mArr(new T[size])
		{
			for (int i = 0; i < mSize; ++i)
			{
				mArr[i] = data;
			}
		}
		~vector()
		{
			delete[] mArr;
			mArr = nullptr;
			mSize = -1;
			mCapacity = -1;
		}

		void push_back(T data)
		{
			if (!mArr)
			{
				mArr = new T[1];
				mCapacity = 1;
				mArr[0] = data;
				mSize = 1;

				return;
			}

			if (mCapacity < mSize+1)
				reserve(mCapacity+1);

			mArr[mSize++] = data;
		}

		void reserve(size_t capacity)
		{
			T* temp = new T[capacity];
			memcpy_s(temp, capacity, mArr, mCapacity);
			T* deleteArr = mArr;
			mArr = temp;

			delete deleteArr;
			deleteArr = nullptr;

			mCapacity = capacity;
		}

		void resize(size_t size)
		{
			if (mCapacity < size)
				reserve(size);
		}
		void resize(size_t size, T data)
		{
			if (mCapacity < size)
				reserve(size);
			int tempSize = mSize;
			for (int i = tempSize; i < size; ++i)
				push_back(data);
		}
		size_t size()
		{
			return mSize;
		}
		T& operator[](size_t index)
		{
			return mArr[index];
		}
	private:
		size_t mSize;
		size_t mCapacity;
		T* mArr;
	};
}
