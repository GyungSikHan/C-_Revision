#include<iostream>

using namespace std;

int groupCount = 4;
int parent[10]{1,1,1,2,2,2,3,3,4,4};

int n{};

int getParet(char c)
{
    return parent[c - 'A'];
}

void Solution(char c1, char c2)
{
	int group1 = getParet(c1);
	int group2 = getParet(c2);

    if (group1 == group2)
        return;

	for (int i = 0; i < 10; ++i)
	{
        if (parent[i] == group2)
            parent[i] = group1;
	}
}

int CountGroup()
{
    int cnt = 1;
    int currGroup = parent[0];
	for (int i = 0; i < 10; ++i)
    {
	    if (currGroup != parent[i])
	    {
            cnt++;
            currGroup = parent[i];
	    }
    }

    return cnt;
}

int main()
{
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
		char c1{}, c2{};
        cin>>c1>>c2;

        Solution(c1,c2);
    }

    cout << CountGroup() << "개" << endl;
    
}