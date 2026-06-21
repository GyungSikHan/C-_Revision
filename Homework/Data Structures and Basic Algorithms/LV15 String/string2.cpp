#include <iostream>
using namespace std;

namespace ya
{
	class string
	{
	public:
		string():mStr(),mSize(),mCapacity(){}
		string(const char* str)
		{
			mSize = strlen(str);
			mCapacity = (mSize * 2) + (mSize / 2);
			mStr = new char[mCapacity];

			memset(mStr,0,mCapacity);
			memcpy_s(mStr, mCapacity, str, mSize + 1);
		}
		string (const string& other)
		{
			mSize = other.mSize;
			mCapacity = other.mCapacity;

			mStr = new char[mCapacity];
			memset(mStr, 0, mCapacity);
			memcpy_s(mStr, mCapacity, other.mStr, other.mSize + 1);
		}
		~string()
		{
			Clear();
		}
		void operator+=(const char* str)
		{
			size_t len = strlen(str);
			size_t newSize = len + mSize;
			if (mCapacity <= len+mSize)
			{
				mCapacity = (newSize * 2) + (newSize / 2);
				char* newStr = new char[mCapacity];
				
				memset(newStr,0,mCapacity);
				memcpy_s(newStr, mCapacity, mStr, mSize + 1);

				delete[] mStr;
				mStr = nullptr;

				mStr = newStr;
			}

			memcpy_s(mStr + mSize, mCapacity - mSize, str, len + 1);
			mSize = newSize;
		}

		char& operator[](int index)
		{
			return mStr[index];
		}

		size_t Size() const
		{
			return mSize;
		}

		const char* c_str() const
		{
			return (mStr ? mStr : "");
		}

		bool IsEmpty() const
		{
			return mSize == 0;
		}

		void Clear()
		{
			delete[] mStr;
			mStr = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

		bool operator==(const char* str) const
		{
			size_t len = strlen(str);
			if (len != mSize)
				return false;

			for (size_t i = 0; i < mSize; ++i)
				if (mStr[i] != str[i])
					return false;
			
			return true;
		}

	private:
		char* mStr;
		size_t mSize;
		size_t mCapacity;
	};
}
int main()
{
	std::string stdStr("Hello");
	stdStr += " World";
	cout << "std::string: " << stdStr << endl;
	cout << "4번째 문자: " << stdStr[4] << endl;
	cout << "-------------------------------------" << endl;

	ya::string myStr("Hello");
	stdStr += " World";
	cout << "초기 문자열: " << myStr.c_str() << endl;
	cout << "길이: " << myStr.Size() << endl;

	myStr += " World";
	cout << "\n 문자열 추가 후: " << myStr.c_str() << endl;
	cout << "길이: " << myStr.Size() << endl;

	myStr[0] = 'h';
	cout << "\n 첫글자 변경 후: " << myStr.c_str() << endl;
	cout << "4번째 문자: " << myStr[4] << endl;
	
	if (myStr == "Hello")
		cout << "같습니다." << endl;
	else
		cout << "다릅니다." << endl;

	if (myStr == "hello World")
		cout << "같습니다." << endl;
	else
		cout << "다릅니다." << endl;

	ya::string myStr2(myStr);
	if (!myStr.IsEmpty())
		myStr.Clear();
	cout << myStr.c_str() << endl;
	cout << myStr2.c_str() << endl;
}