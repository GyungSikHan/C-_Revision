#include <iostream>
using namespace std;

class Date
{
public:
	Date()
		:year(), month(), day(), independenceDay{}
	{}
	Date(int year, int month, int day)
		:year(year),month(month),day(day),independenceDay{}
	{
		
	}
	Date(const char* independence)
		:year(),month(),day(),independenceDay{}
	{
		const wchar_t c[3]{ L'년',L'월',L'일' };
		int idx{};
		int idx2{};

		while (independence[idx] != '\0')
		{
			if (independence[idx] == '/')
				independenceDay[idx] = c[idx2++];
			else
				independenceDay[idx] = (wchar_t)independence[idx];

			idx++;
		}
		independenceDay[idx] = (wchar_t)c[idx2];
		independenceDay[idx+1] = L'\0';

	}
	~Date(){}

	void Show() const
	{
		setlocale(LC_ALL, "");
		wcout << independenceDay<< endl;
	}

	int GetYear()const
	{
		return year;
	}
	int GetMonth()const
	{
		return month;
	}
	int GetDay() const
	{
		return day;
	}

private:
	int year;
	int month;
	int day;
	wchar_t independenceDay[256];
};

int main()
{
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.Show();
	cout << birth.GetYear() << "," << birth.GetMonth() << "," << birth.GetDay() << endl;
}