#include<iostream>
using namespace std;

void InputNum(int* input)
{
    cin>>*input;
}

void Move(int* y, int* x, const int input, int move)
{
    if (move == input)
        return;

    char str[256]{};
    cin >> str;

    if (strcmp(str, "up") == 0)
        *y = (*y) - 1;
    else if(strcmp(str, "down")== 0)
        *y = (*y) + 1;
    else if(strcmp(str ,"right") == 0)
        *x = (*x) + 1;
    else if(strcmp(str ,"left") == 0)
        *x = (*x) - 1;
	Move(y, x, input, move + 1);
}

int main()
{
    int y=5,x = 5;
    int input{};

    InputNum(&input);
    Move(&y,&x,input,0);

    cout << y << "," << x;
}