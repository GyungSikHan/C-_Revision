#include<iostream>
using namespace std;

int main()
{
    int input{};
    cin>>input;
    
    int a = input / 1000;
    input %= 1000;
    int b= input /100;
    input %= 100;
    int c = input / 10;
    input %= 10;
    int d = input;

    cout<<"숫자"<<a<<endl;
    cout<<"숫자"<<b<<endl;
    cout<<"숫자"<<c<<endl;
    cout<<"숫자"<<d<<endl;
}