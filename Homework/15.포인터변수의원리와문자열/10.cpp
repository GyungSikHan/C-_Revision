#include<iostream>
using namespace std;

int main()
{
    char arr[8]{'A','B','C','Z','E','T','Q'};
    char list[6];

    cin>>list;

    for (int i = 0; i < 5; i++)
    {
        bool bFlag{};
        for (int j = 0; j < 7; j++)
        {
            if(list[i] == arr[j])
            {
                bFlag= true;
                break;
            }
        }
        if(bFlag)
            cout<<list[i]<<"=마을사람"<<endl;
        else
            cout<<list[i]<<"=외부사람"<<endl;
        
    }
    
    
}