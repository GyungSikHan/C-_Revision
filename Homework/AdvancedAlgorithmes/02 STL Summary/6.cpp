#include<iostream>
#include<map>
using namespace std;

int cnt{}, cnt2{};
vector<vector<string>> v{};

int main()
{
    cin>>cnt>>cnt2;
    v.assign(cnt, vector<string>());
    for(int i = 0; i < cnt2; i++)
    {
        int n{};
        string name{};

        cin>>n>>name;
        v[n].push_back(name);
    }

    int maxIdx = 0;
    int maxCnt = v[0].size();
    for (size_t i = 1; i < cnt; i++)
    {
        if(maxCnt < v[i].size())
        {
            maxCnt = v[i].size();
            maxIdx = i;
        }
    }

    for(const auto& iter : v[maxIdx])
        cout<<iter<<" ";
}