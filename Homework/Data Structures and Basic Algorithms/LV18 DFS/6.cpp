#include<iostream>
#include<vector>
using namespace std;

const int SIZE = 100;

int matrix[SIZE][SIZE]{};
std::vector<int> v;

void Print()
{
    for(auto iter : v)
        cout<< iter <<" ";
    cout<<endl;
}

void DFS(const int size,int idx)
{
    bool bFlag{};
    for (size_t i = 0; i < size; i++)
    {
        if(matrix[idx][i] == 1)
        {
            bFlag = true;
            v.push_back(i);
            DFS(size, i);
            v.pop_back();
        }
    }

    if(bFlag == false)
        Print();
    
}

int main()
{
    int n{};
    cin>>n;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            cin>>matrix[i][j];   
    v.push_back(0);   

    DFS(n, 0);
}

