#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int N,M;
int map[101][101];
int geori[101][101] = { 0, };
int gg;
bool check[101][101] = { false, };
int r,s;
int result = 98765432;

void dfs(int xpos, int ypos, int cnt)
{
	if (cnt == M)
	{
		memset(geori, 0, sizeof(geori));
		r = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (check[i][j]) //치킨집이면 돌아
				{
					for (int m = 0; m < N; m++)
					{
						for (int n = 0; n < N; n++)
						{
							if (map[m][n] == 1) //집을 찾으면
							{
								s = abs(i - m) + abs(j - n);
								if (geori[m][n] == 0 || s < geori[m][n]) //거리가 0일수는 없으므로 0이라면 초기값으로 가정
									geori[m][n] = s; //각각의 치킨거리를 설정
							}
						}
					}
				}
			}
		}

		for (int m = 0; m < N; m++) //집까지의 치킨거리의 합을 구하는 곳
		{
			for (int n = 0; n < N; n++)
			{
				if (map[m][n] == 1) //집을 찾으면
				{
					r += geori[m][n]; //치킨거리를 더해준다.
				}
			}
		}

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << check[i][j] << " ";
			}
			cout << endl;
		}
		cout << r << endl << endl;*/

		if (result > r)
			result = r;

		return;
	}
	else // 2인 치킨집을 설정하면 cnt늘려서 재귀돌려 
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 2&&!check[i][j])
				{
					check[i][j] = true;
					dfs(i, j, cnt + 1);
					check[i][j] = false;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >>N>> M;

	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(0, 0, 0);
	cout << result;
	return 0;
}