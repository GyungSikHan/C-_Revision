#include <iostream>
using namespace std;

namespace ya
{
	class string
	{
	public:
		string(const char* str)
		{
			mSize = strlen(str);
			mCapacity = (mSize * 2) + (mSize / 2);
			if (!mCapacity)
				mCapacity = 1;

			mStr = new char[mCapacity] {};
			memset(mStr, 0, mCapacity);
			memcpy(mStr, str, mSize + 1);
		}

		~string()
		{
			if (mStr)
			{
				delete[] mStr;
				mStr = nullptr;
			}
		}

		void operator+=(const char* str)
		{
			int len = strlen(str);
			int newSize = mSize + len;

			if (newSize >= mCapacity)
			{
				mCapacity = (newSize * 2) + (newSize / 2);

				char* newStr = new char[mCapacity] {};
				memset(newStr, 0, mCapacity);
				memcpy(newStr, mStr,mSize);

				delete mStr;

				mStr = newStr;
			}

			memcpy(mStr+mSize, str, len+1);
			mSize = newSize;
		}

		char& operator[](int idx)
		{
			return mStr[idx];
		}
		int Size() const
		{
			return mSize;
		}
		const char* c_str() const
		{
			return mStr;
		}

	private:
		char* mStr;
		int mSize;
		int mCapacity;
	};
}
int main()
{
	ya::string s("Hello");
	cout << "처음: " << s.c_str() << endl;
	s += "World";
	cout << "변경 후: " << s.c_str() << endl;
	cout << "길이: " << s.Size() << endl;
	cout << "인덱스[1]: " << s[1] << endl;
}