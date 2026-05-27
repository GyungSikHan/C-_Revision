#include <iostream>
using namespace std;

const int len = 100001;

struct node
{
    int data;
    int num;
};

int main()
{
    int n{};
    int nums[len]{};
    int k{};

    cin>>n; 

    for (size_t i = 0; i < n; i++)
        cin>>nums[i];
    cin>>k;
    const int retK = k;


    for (int i = 1; i < n; i++)
    {
        int data = nums[i];
        int idx = i;
        for (int j = i-1; j >= 0; j--)
        {
            if(data < nums[j])
            {
                nums[idx] = nums[j];
                idx = j;
            }
            else
                break;
        }
        nums[idx] = data;
    }

    int ret[20005]{};
    for (size_t i = 0; i < n; i++)
    {
        int temp = nums[i];
        if(temp < 0)
            temp = std::abs(temp) + 10000;
        ret[temp]++;
    }

    int index[20005]{};
    int idx{};
    while (idx < k)
    {
        int max = -987654321;
        for (size_t i = 0; i < 20005; i++)
        {
            if(max < ret[i])
            {
                max = ret[i];
                index[idx] = i;
            }
        }
        ret[index[idx]] = 0;
        idx++;
    }

    for (size_t i = 0; i < k; i++)
    {
        cout<<(index[i] > 10000 ? 10000-index[i] : index[i]);
        if(i + 1 != k)
            cout<<",";
    }
    
    
}