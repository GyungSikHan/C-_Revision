#include<iostream>
using namespace std;

int main()
{
    char str[3][256]{};
    for (size_t i = 0; i < 3; i++)
        cin>>str[i];
    
    int ret{};
    for (size_t i = 0; i < 2; i++)
    {
        int flag{};
        for (size_t j = 0; j < 3; j++)
        {
            if(i != j)
            {
                if(strcmp(str[i], str[j]) == 0)
                    flag++;
            }
        }
        if(flag == 1)
            ret = 1;
        else if(flag == 2)
        {
            ret = 2;
            break;
        }
    }
    
    if(ret == 2)
        cout<<"WOW";
    else if(ret == 1)
        cout<<"GOOD";
    else    
        cout<<"BAD";
}