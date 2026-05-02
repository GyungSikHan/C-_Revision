#include<iostream>
using namespace std;

void InputPassword(int* input)
{
    for (size_t i = 0; i < 4; i++)
    {
        cin>>input[i];
    }
}

bool IsSame(int* password, int* input)
{
    for (size_t i = 0; i < 4; i++)
    {
        if(password[i] != input[i])
            return false;
    }
    return true;
}

int main()
{
    int password[4]{3,7,4,9};
    int input[4]{};
    
    InputPassword(input);
    
    if(IsSame(password, input))
        cout<<"pass";
    else   
        cout<<"fail";

}