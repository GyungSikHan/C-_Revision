#include<iostream>
using namespace std;

char arr[26]{};

void Dople(string str)
{
    for (size_t i = 0; i < str.size(); i++)
        arr[str[i] - 'A']++;
}

int main()
{
    string str{};
    cin>>str;

    Dople(str);
    for (size_t i = 0; i < 26; i++)
        if(arr[i] >= 2)
            cout<<(char)(i+'A');
}