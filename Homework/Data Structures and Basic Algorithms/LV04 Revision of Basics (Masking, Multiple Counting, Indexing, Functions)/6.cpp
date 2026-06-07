#include<iostream>

using namespace std;

int main()
{
   bool mask[2][5]{{0,0,1,0,0},{0,0,1,1,1}};
   int arr[2][5]{{3,5,4,1,1}, {3,5,2,5,6}};

   int a{};
   cin>>a;

   bool bFlag{};
   for (size_t i = 0; i < 2; i++)
   {
        for (size_t j = 0; j < 5; j++)
        {
            if(mask[i][j] == 0)
                continue;

            if(arr[i][j] == a)
            {
                bFlag = true;
                break;
            }
        }
        if(bFlag)
            break;
   }
   
    if(bFlag)
        cout<<a<<"존재";
    else
        cout<<a<<"없음";

}