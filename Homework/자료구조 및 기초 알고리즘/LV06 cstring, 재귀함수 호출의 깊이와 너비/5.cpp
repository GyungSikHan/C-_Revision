#include<iostream>
using namespace std;

void InputSTR(char* str)
{
    cin>>str;
}

void Solve(char (*str)[11])
{
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = i+1; j < 3; j++)
        {
            if(strlen(str[i]) < strlen(str[j]))
            {
                char* temp{};
                strcpy(temp, str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
    
}

void Print(char (*str)[11])
{
    for (size_t i = 0; i < 3; i++)
    {
        cout<<str<<endl;
    }
    
}

int main()
{
    char str[3][11]{};

    for (size_t i = 0; i < 3; i++)
        InputSTR(str[i]);
    Solve(str);
    Print(str);
}