#include<iostream>

using namespace std;

struct Point
{
    int y;
    int x;
    string str;
};

int map[3][3]{};
int n{};
int cnt{};
vector<Point> v;

void Erase()
{
    for (size_t i = 0; i < v.size(); i++)
    {
        string& str = v[i].str;
        if(str == "\0")
            continue;
        int temp = str.at(str.size()-1) - '0';
        temp -= n;

        if(temp <= 0)
            str.erase(str.size()-1);
        else
            str.at(str.size()-1) = temp+'0';
    }
}

int main()
{
    cin>>n;
    v.assign(n, Point());
    for (size_t i = 0; i < n; i++)
        cin>>v[i].y>>v[i].x>>v[i].str;
    cin>>cnt;
    for (size_t i = 0; i < cnt; i++)
    {
        cin>>n;
        Erase();
    }
    
    int cnt{};
    for (const auto& iter : v)
    {
        if(iter.str != "\0")
            cnt += iter.str.size();
    }
    
    cout<<cnt;
}