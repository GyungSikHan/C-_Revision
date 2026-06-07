#include<iostream>
using namespace std;

void abc(char* arr, int len, int len2, char* str, char* str2)
{
    if(len == 4)
    {
        str[len] = arr[len];
        str2[len2] = arr[len];
        return;
    }

    str[len] = arr[len];
    abc(arr, len+1, len2-1, str, str2);
    str2[len2] = arr[len];
}

int main()
{
    char arr[5]{};
    for (size_t i = 0; i < 5; i++)
        cin>>arr[i];
    
    char str[5]{};
    char str2[5]{};

    abc(arr, 0, 4, str,str2);

    cout<<str<<endl;
    cout<<str2<<endl;
}