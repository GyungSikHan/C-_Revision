#include<iostream>
using namespace std;

int coin[4]{35,17,7,1};
int counts[4]{};

void Solution(int ret, int idx,const int input)
{
    if(ret > input)
        return;
    if(ret == input)
        return;

    if(input >= ret + coin[idx])
    {
        counts[idx]++;
        Solution(ret + coin[idx], idx, input);
    }
    else
        Solution(ret, idx+1, input);
}

int main()
{
    int input{};
    cin>>input;

    Solution(0, 0, input);

    for(int i = 0; i < 4; i++)
        cout<<coin[i]<<":"<<counts[i]<<"개"<<endl;
}