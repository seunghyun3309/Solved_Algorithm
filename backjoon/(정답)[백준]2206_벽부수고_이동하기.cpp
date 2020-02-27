#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 87654321
using namespace std;

const int MAX = 1010;

int map[MAX][MAX][2] = { 0, };
int arr[MAX][MAX];

int x, y, z, nx, ny, nz;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<int> x_cnt;
	queue<int> y_cnt;
	queue<int> z_cnt;
	int n, m;
	cin >> n >> m;
	string input;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = input[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k <= 1; k++)
			{
				map[i][j][k] = INF;
			}

		}
	}

	//0,0에서 시작
	x_cnt.push(0);
	y_cnt.push(0);
	z_cnt.push(0);

	map[0][0][0] = 1;

	while (!x_cnt.empty())
	{
		x = x_cnt.front();
		y = y_cnt.front();
		z = z_cnt.front();

		x_cnt.pop();
		y_cnt.pop();
		z_cnt.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= n || nx < 0 || ny >= m || ny < 0)
			{
				continue;
			}

			if (arr[nx][ny] == 0 && (map[x][y][z] + 1 < map[nx][ny][z]))
			{
				map[nx][ny][z] = map[x][y][z] + 1;
				x_cnt.push(nx);
				y_cnt.push(ny);
				z_cnt.push(z);

			}
			if (z == 0 && arr[nx][ny] == 1 && (map[x][y][0] + 1 < map[nx][ny][1]))
			{
				map[nx][ny][1] = map[x][y][0] + 1;

				x_cnt.push(nx);
				y_cnt.push(ny);
				z_cnt.push(1);
			}

		}
	}

	int min = map[n - 1][m - 1][0] < map[n - 1][m - 1][1] ? map[n - 1][m - 1][0] : map[n - 1][m - 1][1];

	if (min == INF)
	{
		cout << -1;
	}
	else
	{
		cout << min;
	}
}

