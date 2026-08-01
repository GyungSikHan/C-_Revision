#include <iostream>
using namespace std;

class SortedArray
{
private:
	int size; // 현재 배열의 크기
	int* p; // 정수 배열에 대한 포인터
	void sort() // 정수 배열을 오름차순으로 정렬
	{
		for (int i = 1; i < size; ++i)
		{
			int key = i;
			int val = p[i];
			for (int j = i-1; j >= 0; --j)
			{
				if (p[j] > val)
				{
					p[key] = p[j];
					key = j;
				}
				else
					break;
			}
			p[key] = val;
		}
	}
public:
	SortedArray() // p는 NULL로 size는 0으로 초기화
		:p(), size()
	{
		
	}
	SortedArray(const SortedArray& src) // 복사 생성자
	{
		size = src.size;
		p = new int[size];
		memcpy(p, src.p, sizeof(int)*size);
	}
	SortedArray(int p[], int size) // 생성자. 정수 배열과 크기를 전달받음
	{
		this->p = new int[size];
		this->size = size;

		memcpy(this->p, p, sizeof(int) * size);

		sort();
	}
	~SortedArray() // 소멸자
	{
		delete[] p;
		p = nullptr;
		size = 0;
	}
	SortedArray operator+ (SortedArray& op2) // 현재 배열에 op2 배열 추가
	{
		int tempsize = this->size + op2.size;
		int* tempArr = new int[tempsize];

		memcpy(tempArr, this->p,sizeof(int) * this->size);
		memcpy(tempArr+this->size, op2.p, sizeof(int) * op2.size);
		
		SortedArray result(tempArr, tempsize);

		delete[] tempArr;
		return result;
	}
	SortedArray& operator= (const SortedArray& op2) // 현재 배열에 op2 배열 복사
	{
		SortedArray temp(op2);

		std::swap(p, temp.p);
		std::swap(size, temp.size);

		return *this;
	}
	void show()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b; 
	// +, = 연산자 작성 필요
	// + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요

	a.show();
	b.show();
	c.show();
}
