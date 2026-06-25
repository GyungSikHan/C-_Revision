#include<iostream>
using namespace std;

char arr[4][10]{};
int length[4];

void CheckLength(int idx)
{
    length[idx] = strlen(arr[idx]);
}

void MinMax(int& minIdx, int& maxIdx)
{
        int Min = 987654321;
    int Max = -1;
    for(int i = 0; i < 4; i++)
    {
        if(Max < length[i])
        {
            Max = length[i];
            maxIdx = i;    
        }
        if(Min > length[i])
        {
            Min = length[i];
            minIdx = i;
        }
    }
}

void Lower(int idx)
{
    for(int i = 0; i < strlen(arr[idx]); i++)
        arr[idx][i] = std::tolower(arr[idx][i]);
}

int main()
{
    for (size_t i = 0; i < 4; i++)
        cin>>arr[i];
    for (size_t i = 0; i < 4; i++)
        CheckLength(i);

    int minIdx{}, maxIdx{};
    MinMax(minIdx,maxIdx);

    Lower(minIdx);
    Lower(maxIdx);

    for(int i = 0; i < 4; i++)
        cout<<arr[i]<<endl;
}