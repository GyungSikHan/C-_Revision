#include<iostream>
using namespace std;

void Move(char* str, int* curr)
{
    if(strcmp(str, "up") == 0)
        *curr +=1;
    else
        *curr -= 1;
}

void Print(const int* curr)
{
    if(*curr > 0)
        cout<<*curr<<"층"<<endl;
    else
    {
        int cu = std::abs(*curr)+1;
        cout<<"B"<< cu<<"층"<<endl;
    }
}

int main()
{
   int curr = 1;

   for (size_t i = 0; i < 5; i++)
    {
        char str[5]{};
        cin>>str;

        Move(str, &curr);
    }
   
    Print(&curr);
}