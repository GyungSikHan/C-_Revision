#include <iostream>
#include <vector>
#include <queue>
#include<string>

using namespace std;

void Zigzag(const int& level, const vector<int>& v, queue<int>& qu, const int curr)
{
    int next{};
    if (level % 2 == 0)
    {
        next = curr * 2 + 1;
        if (next < v.size() && v[next] != -1)
            qu.push(next);

        next -= 1;
        if (next < v.size() && v[next] != -1)
            qu.push(next);
    }
    else if (level % 2 == 1)
    {
        next = curr * 2;
        if (next < v.size() && v[next] != -1)
            qu.push(next);

        next += 1;
        if (next < v.size() && v[next] != -1)
            qu.push(next);
    }
}
void BFS(const vector<int>& v)
{
    queue<int> qu;
    qu.push(1);

    int level = 0;
    while (!qu.empty())
    {
        int curr = qu.front();
        qu.pop();

        if (curr / 2 != level)
        {
            cout << endl;
            level = curr / 2;
        }
        Zigzag(level, v, qu, curr);
        cout << v[curr] << " ";
    }

}

int main()
{
    int n{};
    cin >> n;
    vector<int> v(n + 1, -1);
    for (size_t i = 1; i <= n; i++)
    {
        string str{};
        cin >> str;

        if (str != "null")
            v[i] = stoi(str);
    }

    BFS(v);
}