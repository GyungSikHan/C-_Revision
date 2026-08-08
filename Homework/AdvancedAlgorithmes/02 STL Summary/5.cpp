#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n{};
vector<string> v;

bool compare(const string a, const string b)
{
    if(a.size() == b.size())
    {
        for (size_t i = 0; i < a.size(); i++)
        {
            if(a.at(i) < b.at(i))
                return true;
            else if(a.at(i) > b.at(i))
                return false;
        }
        
    }

    return a.size() < b.size();
}
int main()
{
    cin>>n;
    v.assign(n,"");
    for (size_t i = 0; i < n; i++)
        cin>>v[i];
    
    sort(v.begin(), v.end(), compare);

    for(const auto& iter : v)
        cout<<iter<<endl;
}