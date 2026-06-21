#include <iostream>
using namespace std; 

namespace ya
{
	class string
	{
	public:
		string() :mStr{}, mStrSize(), mCapacity() {}
		string(const char* str)
		{
			mStrSize = strlen(str);
			mCapacity = (mStrSize * 2) + (mStrSize / 2);

			mStr = new char[mCapacity];
			memset(mStr, 0, mCapacity);
			memcpy_s(mStr, mCapacity, str, mStrSize+1);
		}
		~string()
		{
			delete[] mStr;
			mStr = nullptr;
			mStrSize = 0;
			mCapacity = 0;
		}

		void operator+=(const char* str)
		{
			size_t len = strlen(str);
			size_t newSize = len + mStrSize;

			if (mCapacity <= newSize)
			{
				mCapacity = (newSize * 2) + (newSize / 2);
				char* newStr = new char[mCapacity];
				memset(newStr,0, mCapacity);
				memcpy_s(newStr, mCapacity, mStr, mStrSize + 1);

				delete[] mStr;
				mStr = nullptr;
				mStr = newStr;
			}
			memcpy_s(mStr+mStrSize, mCapacity - mStrSize, str, len+1);
			mStrSize = newSize;
		}

		char& operator[](int index)
		{
			return mStr[index];
		}

		size_t size() const
		{
			return mStrSize;
		}

		const char* c_str()const
		{
			return mStr;
		}
	private:
		char* mStr;
		size_t mStrSize;
		size_t mCapacity;
	};
	
}

int main()
{
	std::string stdStr("Hello");
	stdStr += " World";
	cout << "std::string: " << stdStr << endl;
	cout << "4번째 문자: " << stdStr[4] << endl;
	cout << "-------------------------------------"<< endl;

	ya::string myStr("Hello");
	stdStr += " World";
	cout << "초기 문자열: " << myStr.c_str() << endl;
	cout << "길이: " << myStr.size() << endl;
	
	myStr += " World";
	cout << "\n 문자열 추가 후: " << myStr.c_str() << endl;
	cout << "길이: " << myStr.size() << endl;

	myStr[0] = 'h';
	cout << "\n 첫글자 변경 후: " << myStr.c_str() << endl;
	cout << "4번째 문자: " << myStr[4] << endl;
}