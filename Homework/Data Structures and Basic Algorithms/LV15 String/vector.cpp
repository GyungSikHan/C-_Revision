#include <iostream>
using namespace std;

namespace ya
{
	template <typename T>
	class vector
	{
	public:
		vector() :mCapacity(), mSize(), arr(), index() {}
		~vector()
		{
			clear();
		}

		void push_back(T data)
		{
			if (mCapacity == 0)
				reserve(10);
			else if (mCapacity <= mSize)
			{
				resize(mCapacity+1);
			}

			arr[index] = data;
			if (index == mSize)
				mSize++;
			index++;
		}

		void clear()
		{
			delete[] arr;
			arr = nullptr;
			mSize = 0;
			mCapacity = 0;
			index = 0;
		}
		void resize(int newSize)
		{
			if (arr == nullptr)
			{
				mCapacity = (newSize*2) +(newSize/2);
				arr = new T[mCapacity];
				memset(arr, 0, mCapacity*sizeof(T));
				mSize = newSize;
				return;
			}
			
			T* temp = new T[mCapacity];
			memset(temp, 0, mCapacity*sizeof(T));

			if (mSize != 0)
				memcpy_s(temp, mCapacity, arr, newSize);

			delete[] arr;
			arr = nullptr;
			arr = temp;
			mSize = newSize;
		}
		void reserve(int size)
		{
			T init{};
			mCapacity = size;
			T* temp = new T[mCapacity];
			memset(temp, init, mCapacity);
			
			if (mSize != 0)
				memcpy_s(temp, mCapacity, arr, mSize);
			
			delete[] arr;
			arr = nullptr;
			arr = temp;
		}

		T& operator[](int index)
		{
			return arr[index];
		}
		size_t size() const
		{
			return mSize;
		}
	private:
		int index;
		size_t mSize;
		size_t mCapacity;
		T* arr;
	};
}

int main()
{
	ya::vector<int> vec;
	vec.resize(100);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	cout << vec[0] << endl;
	cout << vec.size() << endl;
}