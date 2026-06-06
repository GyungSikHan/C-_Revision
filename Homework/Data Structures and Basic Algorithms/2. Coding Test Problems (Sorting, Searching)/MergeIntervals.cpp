#include <iostream>
using namespace std;

struct Node
{
    int start;
    int end;
};


int main()
{
    int n{};
	Node node[10001]{};

    cin>>n;
    for (size_t i = 0; i < n; i++)
        cin>>node[i].start>>node[i].end;
    
    for (size_t i = 1; i < n; i++)
    {
        Node data = node[i];
        int idx = i;
        for (int j = i-1; j >= 0; j--)
        {
            if(data.start < node[j].start)
            {
                node[idx] = node[j];
                idx = j;
            }
        }
        node[idx] = data;
    }

    int idx{};
    bool visited[10001]{};
    Node ret[10001]{};
    for (size_t i = 0; i < n; i++)
    {
        if(visited[i] )
            continue;

        visited[i] = true;
        ret[idx] = node[i];
        for (size_t j = i+1; j < n; j++)
        {
            if(ret[idx].end >= node[j].start)
            {
                visited[j] = true;
                ret[idx].end = node[j].end;
            }
        }
        idx++;
    }

    for (size_t i = 0; i < idx; i++)
    {
        cout<<ret[i].start<<","<<ret[i].end<<endl;
    }
    
    
}