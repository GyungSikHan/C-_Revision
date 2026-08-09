#include <iostream>
#include <queue>

using namespace std;

const int col = 4;
const int row = 8;
const int dy[8]{ -1,-1,0,1,1,1,0,-1 };
const int dx[8]{ 0,1,1,1,0,-1,-1,-1 };
int map[col][row]{};

int main()
{
	for (int i = 0; i < col; ++i)
		for (int j = 0; j < row; ++j)
			cin >> map[i][j];


	int ret = -1;
	for (int sy = 0; sy < col; ++sy)
	{
		for (int sx = 0; sx < row; ++sx)
		{
			for (int ey = 0; ey < col; ++ey)
			{
				for (int ex = 0; ex < row; ++ex)
				{
					auto Check = [&]()
						{
							int sum{};
							for (int i = sy; i <= ey; ++i)
							{
								for (int j = sx; j <= ex; ++j)
								{
									if (map[i][j] == 0)
										return -1;

									sum += map[i][j];
								}
							}
							return sum;
						};

					int temp = Check();
					if (temp == -1)
						continue;
					ret = max(ret, temp);
				}
			}
		}
	}

	cout << ret;
}