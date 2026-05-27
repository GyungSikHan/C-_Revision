#include<iostream>
using namespace std;

int main()
{
    string str[4]{};
    int max = -987654321;
    int maxIdx{};
    int min = 987654321;
    int minIdx{};

    for (size_t i = 0; i < 4; i++)
        cin>>str[i];
    
    for (size_t i = 0; i < 4; i++)
    {
        int temp = strlen(str[i].c_str());

        if(temp < min)
        {
            min = temp;
            minIdx = i;
        }
        if(max < temp)
        {
            max = temp;
            maxIdx = i;
        }
    }
    
    cout<<"긴문장:"<<maxIdx<<endl;
    cout<<"짧은문장:"<<minIdx<<endl;
}