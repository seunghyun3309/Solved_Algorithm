#include <iostream>
#include <string>
#include <queue>
using namespace std;

int m, n;
int t, x, y;

int Graph[101][101] = { 0, };
bool check[101][101] = { false, };
char map[101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };
int result[101][101] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		Graph[i][j] = 0;
	//		check[i][j] = false;
	//	}
	//}

	for (int i = 0; i < n; i++)//m번 입력 받기
	{
		cin >> map;
		for (int j = 0; j < m; j++)
		{
			Graph[i][j] = map[j] - '0';
		}

	}

	/*	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout<<Graph[i][j]<<" " ;
			}
			cout << "\n";
		}*/

	x = 0, y = 0;

	queue<int> x_cnt;
	queue<int> y_cnt;

	x_cnt.push(0);
	y_cnt.push(0);

	while (!x_cnt.empty() && !y_cnt.empty())
	{
		x = x_cnt.front();
		y = y_cnt.front();

		for (int i = 0; i < 4; i++)
		{
			if (Graph[x + dx[i]][y + dy[i]] == 1 && check[x + dx[i]][y + dy[i]] == false)
			{
				check[x + dx[i]][y + dy[i]] = true;
				x_cnt.push(x + dx[i]);
				y_cnt.push(y + dy[i]);

				result[x + dx[i]][y + dy[i]] = result[x][y] + 1;
			}
			if (x == n - 1 && y == m - 1)
			{
				break;
			}
		}
		x_cnt.pop();
		y_cnt.pop();
	}

	cout << result[n - 1][m - 1] + 1;

	return 0;
}

