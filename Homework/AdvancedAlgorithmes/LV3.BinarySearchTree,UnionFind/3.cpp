#include<iostream>

using namespace std;

const int length = 5;

int targets[length]{};
int BinarySearchTree[]{0,15,7,19,0,8,17,25,0,0,0,0,16,18,0,0};

int Find(int target)
{
    int cnt{};
    int idx = 1;
    while (BinarySearchTree[idx] != target)
    {
        if(BinarySearchTree[idx] == 0)
            return -1;
        cnt++;
        if(BinarySearchTree[idx] > target)
            idx= idx*2;
        else if(BinarySearchTree[idx] < target)
            idx = idx*2+1;

        if(idx > 16)
            return -1;
    }
    
    return cnt+1;
}

int main()
{
    for (size_t i = 0; i < length; i++)
        cin>>targets[i];
    
    for (size_t i = 0; i < length; i++)
    {
        int ret = Find(targets[i]);
        if(ret == -1)
            cout<<targets[i]<<":없음"<<endl;
        else
            cout<< targets[i]<<":"<<ret<<"회만에 찾음\n";
    }
}