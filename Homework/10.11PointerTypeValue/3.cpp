#include<iostream>
using namespace std;
/*
   번호 순서대로 배열에 값을 채우려 합니다. 숫자 1개를 입력 받아주세요 입력받은 숫자를 5으로 나누었을때 나머지 값이 1이라면
   9 6 3 
   8 5 2 
   7 4 1 
   입력받은 숫자를 5로 나누었을때 나머지 값이 2이라면 
   7 8 9
    4 5 6 
    1 2 3 
    위에 두 경우가 아니라면 
    10 13 16
    11 14 17 
    12 15 18 
    이렇게 값을 채우고 값을 채운 2차배열을 출력 해 주세요.
 */

int main()
{
    int input{}, num = 1;
    int arr[3][3]{};

	cin >> input;
    
	if (input % 5 == 1)
    {
		for (int i = 2; i >= 0; i--)
		{
            for (int j = 2; j >= 0; j--)
            {
                arr[j][i] = num++;
            }
		}
    }
    else if (input % 5 == 2)
    {
	    for (int i = 2; i >= 0; i--)
	    {
		    for (int j = 0; j < 3; j++)
		    {
                arr[i][j] = num++;
		    }
	    }
    }
    else
    {
        num = 10;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[j][i] = num++;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}