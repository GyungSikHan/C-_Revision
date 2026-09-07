#include<iostream>
#include<vector>
using namespace std;

int n{};
vector<int> v{};

int main()
{
    cin>>n;
    v.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin>>v[i];
    
    int cnt{};

    vector<pair<int, int>> index;

    for (int i = 1; i < n; i++)
    {
        if(v[i] == v[i-1])
            cnt++;
        else
            cnt = 1;

        if(cnt == 3)
        {
            for (size_t j = i-2; j <= i; j++)
                v[j] = 987654321;
            cnt = 1;
        }
    }

    sort(v.begin(), v.end());

    auto iter = find(v.begin(), v.end(), 987654321);
    v.erase(iter, v.end());
    for(const auto& iter : v)
        cout<<iter<<" ";
}