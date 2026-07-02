#include <iostream>
#include <vector>
using namespace std;

bool ValidSudoku(vector<vector<int>>& sudoku)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sudoku[i][j] == '.')
				continue;
			for (int k = 0; k < 9; ++k)
			{
				if (j != k && sudoku[i][k] != '.' && sudoku[i][j] == sudoku[i][k])
				{
					cout << "false" << i << " " << k << " " << sudoku[i][k] << endl;
					return false;
				}
				if (i != k && sudoku[k][j] != '.' && sudoku[i][j] == sudoku[k][j])
				{
					cout << "false" << k<< " " << j << " " << sudoku[k][j] << endl;
					return false;
				}
			}

			{
				int y = i / 3;
				int x = j / 3;
				for (int k = y*3; k < y*3+3; ++k)
				{
					for (int l = x*3; l < x*3+3; ++l)
					{
						if (i == k && j == l || sudoku[k][l] == '.')
							continue;
						int temp = sudoku[k][l];
						if (temp == sudoku[i][j])
						{
							cout << "false" << k<< " " << l << " " << temp << endl;
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	//vector<vector<int>> board =
	//{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
	//, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
	//, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
	//, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
	//, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
	//, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
	//, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
	//, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
	//, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

	vector<vector<int>> board =
	{ {'8', '3', '.', '.', '7', '.', '.', '.', '.'}
	, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
	, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
	, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
	, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
	, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
	, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
	, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
	, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

	bool ret = ValidSudoku(board);
	cout << (ret ? "true" : "false");

	return 0;
}
