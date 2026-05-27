#include<iostream>
using namespace std;

void Full(char (*str)[3], const char* c)
{
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            str[i][j] = *c;
}

int main()
{
    char str[3][3][3]{};
    char c{};

    cin>>c;

    for (size_t i = 0; i < 3; i++)
    {
        c += i;
        Full(str[i], &c);
    }
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                cout<<str[i][j][k];
            }
            cout<<endl;
        }
    }
       
}