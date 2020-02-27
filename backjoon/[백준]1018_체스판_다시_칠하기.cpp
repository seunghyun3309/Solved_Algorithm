#include <iostream>

using namespace std;

int m, n;
int cnt = 0;
int min_cnt = 65;

char map[60][60] = { 0, };
char color;
char bw[2] = { 'B','W' };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}



	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				cnt = 0;
				color = bw[k];

				for (int x = 0; x < 4; x++)//x가 1357
				{
					for (int y = 0; y < 4; y++)//y가 1357
					{
						if (map[i + (2 * x + 1)][j + (2 * y + 1)] != color)
						{
							cnt++;
						}
					}
				}
				for (int x = 0; x < 4; x++)//x가 0246
				{
					for (int y = 0; y < 4; y++)//y가 0246
					{
						if (map[i + (2 * x)][j + (2 * y)] != color)
						{
							cnt++;
						}
					}
				}
				for (int x = 0; x < 4; x++) //0246
				{
					for (int y = 0; y < 4; y++)//1357
					{
						if (map[i + (2 * x)][j + (2 * y + 1)] == color)
						{
							cnt++;
						}
					}
				}
				for (int x = 0; x < 4; x++)//1357
				{
					for (int y = 0; y < 4; y++)//0246
					{
						if (map[i + (2 * x + 1)][j + (2 * y)] == color)
						{
							cnt++;
						}
					}
				}

				if (cnt < min_cnt)
					min_cnt = cnt;
			}
		}
	}

	cout << min_cnt;

	return 0;
}
