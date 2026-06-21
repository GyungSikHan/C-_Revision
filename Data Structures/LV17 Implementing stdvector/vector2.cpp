#include <iostream>

template<typename T>
class vector
{
	static constexpr size_t DEFAULT_CAPACITY = 30;
public:
	vector():arr(new T[DEFAULT_CAPACITY]), Size(), Capacity(DEFAULT_CAPACITY){}
	vector(const vector& other):arr(new T[other.Capacity]), Size(other.Size), Capacity(other.Capacity)
	{
		memcpy_s(arr, Capacity * sizeof(T), other.arr, Capacity * sizeof(T));
	}
	~vector()
	{
		delete[] arr;
		Size = 0;
		Capacity = 0;
	}
	
	void push_back(const T& data)
	{
		if (Size >= Capacity)
		{
			size_t newCapacity = (Capacity < DEFAULT_CAPACITY ? DEFAULT_CAPACITY : Capacity * 2);
			T* newArr = new T[newCapacity];
			memset(newArr,0,sizeof(T) * newCapacity);
			memcpy_s(newArr, newCapacity * sizeof(T), arr, Capacity * sizeof(T));

			delete[] arr;
			arr = newArr;
			Capacity = newCapacity;
		}

		arr[Size++] = data;
	}
	void pop_back()
	{
		if (Size < 0 )
			return;
		
		Size--;
	}
	void resize(size_t n, T value = T())
	{
		T* newArr = new T[n];
		memset(newArr, 0, sizeof(T) * n);
		size_t copySize = (Size < n ? Size : n);

		memcpy_s(newArr, n * sizeof(T), arr, copySize * sizeof(T));
		for (size_t i = copySize; i < n; ++i)
			newArr[i] = value;
		
		delete[] arr;
		arr = newArr;
		Size = n;
		Capacity = n;
	}
	void clear()
	{
		Size = 0;
	}

	size_t capacity() const
	{
		return Capacity;
	}
	size_t size() const
	{
		return Size;
	}
	bool empty() const
	{
		return Size == 0;
	}

	vector& operator=(const vector& other)
	{
		if (this != &other)
		{
			if (Capacity < other.Capacity)
			{
				delete[] arr;
				Capacity = other.Capacity;
				arr = new T[Capacity];
			}
			Size = other.Size;
			memcpy_s(arr, Capacity*sizeof(T), other.arr, other.Capacity*sizeof(T));
		}
		return *this;
	}
	bool operator==(const vector& other) const
	{
		if (Size != other.Size)
			return false;
		for (size_t i = 0; i< Size; i++)
		{
			if (arr[i] != other.arr[i])
				return false;
		}
		return true;
	}
	bool operator != (const vector& other) const
	{
		return !(*this == other);		
	}
	T& operator[](size_t index)
	{
		return arr[index];
	}
	const T& operator[](size_t index) const
	{
		return arr[index];
	}
	T& front()
	{
		return arr[0];
	}
	T& back()
	{
		return arr[Size-1];
	}
	T* begin()
	{
		return arr;
	}
	T* end()
	{
		return arr + Size;
	}

private:
	T* arr;
	size_t Size;
	size_t Capacity;
};

int main()
{
	vector<int> vec;
	std::cout << "=== 기본 동작 테스트 ===" << std::endl;
	std::cout << "초기 크기: " << vec.size() << std::endl;
	std::cout << "초기 용량: " << vec.capacity() << std::endl;

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
	vec.resize(15, 99);

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
	vector<int> vec2 = vec;

	std::cout << "원본과 복사본 비교: " << (vec == vec2 ? "같음" : "다름") << std::endl;

	vec2[0] = 100;
	std::cout << "복사본 수정 후 비교: " << (vec == vec2 ? "같음" : "다름") << std::endl;

	std::cout << "원본 첫 요소: " << vec[0] << std::endl;
	std::cout << "복사본 첫 요소: " << vec2[0] << std::endl;
}