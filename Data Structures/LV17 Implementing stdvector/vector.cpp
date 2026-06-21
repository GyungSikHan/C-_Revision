#include <iostream>
using namespace std;

namespace ya
{
	template <typename T>
	class vector
	{
	public:
		vector(size_t cap = DEFAULT_CAP)
			:mArr(new T[cap]),mSize(0),mCapacity(cap)
		{
			
		}
		vector(const vector& other)
			:mArr(new T[other.mCapacity]), mSize(other.mSize), mCapacity(other.mCapacity)
		{
			for (size_t i = 0; i < mSize; ++i)
				mArr[i] = other[i];
		}
		~vector()
		{
			delete[] mArr;
			mArr = nullptr;
		}

		vector& operator=(const vector other)
		{
			if (this != & other)
			{
				if (mCapacity < other.mCapacity)
				{
					delete[] mArr;
					mCapacity = other.mCapacity;
					mArr = new T[mCapacity];
				}

				mSize = other.mSize;
				for (size_t i = 0; i < mSize; ++i)
					mArr[i] = other.mArr[i];
			}
			return *this;
		}

		T& operator[](size_t idx)
		{
			return mArr[idx];
		}
		const T& operator[](size_t idx) const
		{
			return mArr[idx];
		}
		T& front()
		{
			return mArr[0];
		}
		T& back()
		{
			return mArr[mSize - 1];
		}
		T* begin() const
		{
			return mArr;
		}
		T* end() const
		{
			return mArr + mSize;
		}
		void push_back(const T& value)
		{
			if (mSize >= mCapacity)
			{
				size_t newCap = mCapacity < DEFAULT_CAP ? DEFAULT_CAP : mCapacity * 2;
				T* newArr = new T[newCap];

				for (size_t i = 0; i < mSize; ++i)
					newArr[i] = mArr[i];

				delete[] mArr;
				mArr = nullptr;
				mArr = newArr;
				mCapacity = newCap;
			}
			mArr[mSize++] = value;
		}
		void pop_back()
		{
			if (mSize<= 0)
				return;
			mArr[mSize--] = 0;
		}
		void resize(size_t n, T value = T())
		{
			T* newArr = new T[n];
			memset(newArr, 0, sizeof(T) * n);
			size_t copySize = (mSize < n) ? mSize : n;

			for (size_t i = 0; i < copySize; ++i)
				newArr[i] = mArr[i];
			for (size_t i = copySize; i < n; i++)
				newArr[i] = value;

			delete[] mArr;
			mArr = nullptr;
			mArr = newArr;
			mSize = n;
			mCapacity = n;
		}
		void clear()
		{
			mSize = 0;
		}
		size_t capacity() const
		{
			return mCapacity;
		}
		size_t size() const
		{
			return mSize;
		}
		bool empty() const
		{
			return mSize == 0;
		}
		bool operator== (const vector& other)const
		{
			if (mSize != other.size())
				return false;

			for (size_t i = 0; i < mSize; i++)
				if (mArr[i] != other[i])
					return false;
			return true;
		}
		bool operator != (const vector& other) const
		{
			return !(*this == other);
		}

	private:
		static constexpr size_t DEFAULT_CAP = 32;
		T* mArr;
		size_t mSize;
		size_t mCapacity;
	};
}

int main()
{
	ya::vector<int> vec;
	std::cout << "=== 기본 동작 테스트 ===" << std::endl;
	std::cout << "초기 크기: " <<vec.size()<< std::endl;
	std::cout << "초기 용량: " <<vec.capacity()<< std::endl;

	for (int i = 1; i <= 5; ++i)
		vec.push_back(i);
	
	std::cout << "\n 4개 요소 추가 후: " << std::endl;
	std::cout << "크기: " << vec.size() << std::endl;
	std::cout << "용량: " << vec.capacity() << std::endl;

	std::cout << "요소들: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "반복자로 출력: ";
	for (auto iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::cout << "\n=== resize 테스트 ===" << std::endl;
	vec.resize(15,99);

	vec[0] = 2;
	vec[10] = 2;

	std::cout << "resize(15, 99) 후: " << std::endl;
	std::cout << "크기: " << vec.size() << std::endl;

	std::cout << "처음 15개 요소: ";

	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== 접근 함수 테스트 ===" << std::endl;
	std::cout << "첫 번째 요소: " << vec.front() << std::endl;
	
	std::cout << "마지막 요소: " << vec.back() << std::endl;

	std::cout << "\n=== 복사 생성자 테스트 ===" << std::endl;
	ya::vector<int> vec2 = vec;

	std::cout << "원본과 복사본 비교: " << (vec == vec2 ? "같음" : "다름") << std::endl;

	vec2[0] = 100;
	std::cout << "복사본 수정 후 비교: " << (vec == vec2 ? "같음" : "다름") << std::endl;

	std::cout << "원본 첫 요소: " << vec[0] << std::endl;
	std::cout << "복사본 첫 요소: " << vec2[0] << std::endl;
}
