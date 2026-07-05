#include <iostream>
using namespace std;

#define MAX_LENGTH 100

int main()
{
    int arr[MAX_LENGTH][MAX_LENGTH]{};
    int n{};

    cin >> n;

    

    int boss;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(j == 0 && arr[i][j] == 1)
            {
                boss = i; 
            }
        }
    }


    cout<<"boss:"<<boss<<endl;
    cout<<"under:";
    for (size_t i = 0; i < n; i++)
    {
        if(arr[0][i] == 1)
            cout<<i<<" ";
    }
    
    

}
