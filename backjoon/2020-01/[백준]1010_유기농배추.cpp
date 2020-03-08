#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int m, n, k;
int t, x, y;

int Graph[60][60] = {0, };
bool check[60][60] = { false, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

int result = 0;

void dfs(int x, int y)
{
	check[x][y] = true;

	for (int c = 0; c < 4; c++)
	{
		if (Graph[x + dx[c]][y + dy[c]] == 1 && check[x + dx[c]][y + dy[c]] == false)
		{
			dfs(x + dx[c], y + dy[c]);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	for (int tc = 0; tc < t; tc++)
	{
		result = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				Graph[i][j] = 0;
				check[i][j] = false;
			}
		}

		for (int i = 0; i < k; i++)//k번 입력 받기
		{
			cin >> y >> x;
			Graph[x][y] = 1;
		}

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout<<Graph[i][j]<<" " ;
		//	}
		//	cout << "\n";
		//}



		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Graph[i][j] == 1 && check[i][j] == false)
				{
					dfs(i, j);
					result++;
				}
			}
		}
		cout << result<<"\n";
	}

	return 0;
}

