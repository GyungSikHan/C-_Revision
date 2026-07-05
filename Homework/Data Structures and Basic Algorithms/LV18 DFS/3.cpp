#include<iostream>
using namespace std;

char node[9]{'\0','A','D','F','Z','C','G','Q','H'};

int main()
{
    char child{}, parent{};

    cin>>child >> parent;

    for(int i = 0; i < 9; i++)
    {
        if(node[i] == child)
        {
            if(node[i/2] == parent)
                cout<<"부모자식관계"<<endl;
            else
                cout<<"아님"<<endl;
            break; 
        }
    }

}