#include<iostream>
using namespace std;

void Sort(char (*str)[11])
{
    for (size_t i = 0; i < 3; i++)
    {
        int len = strlen(str[i]);
        int idx = i;
        for (size_t j = i+1; j < 4; j++)
        {
           int len2 = strlen(str[j]);
           if(len2 < len)
           {
                len = len2;
                idx = j;
           }
        }
        
        char temp[11]{};
        strcpy_s(temp, sizeof(temp), str[i]);
        strcpy_s(str[i], sizeof(str[i]), str[idx]);
        strcpy_s(str[idx], sizeof(str[idx]), temp);
    }
}

int main()
{
    char str[4][11]{};

    for (size_t i = 0; i < 4; i++)
    {
        cin>>str[i];
    }
    
    Sort(str);

    for (size_t i = 0; i < 4; i++)
    {
        cout<<str[i]<<endl;
    }
    
}