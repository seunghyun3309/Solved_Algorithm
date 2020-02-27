#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
int n, m;
int year = 0;
int cnt = 0;

int arr[333][333];
int adj[333][333] = { 0, };
bool check[333][333] = { false, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int x_cnt, y_cnt;

struct bfs {
	int xpos;
	int ypos;
};
queue<bfs> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] > 0 && !check[i][j])
				{
					cnt++;
					check[i][j] = true;
					q.push({ i,j });
					while (!q.empty())
					{
						for (int d = 0; d < 4; d++)
						{
							x_cnt = q.front().xpos + dx[d];
							y_cnt = q.front().ypos + dy[d];
							if (arr[x_cnt][y_cnt] > 0 && !check[x_cnt][y_cnt] && x_cnt >= 0 && x_cnt < n && y_cnt >= 0 && y_cnt < m)
							{
								q.push({ x_cnt,y_cnt });
								check[x_cnt][y_cnt] = true;
							}
						}
						q.pop();
					}
				}
			}
		}
		if (cnt != 1)
			break;
		else
		{
			memset(check, false, sizeof(check));
			memset(adj, 0, sizeof(adj));
			cnt = 0;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (arr[i][j] > 0)
					{
						for (int d = 0; d < 4; d++)
						{
							x_cnt = i + dx[d];
							y_cnt = j + dy[d];
							if (arr[x_cnt][y_cnt] <= 0 && x_cnt >= 0 && x_cnt < n && y_cnt >= 0 && y_cnt < m)
								adj[i][j]++;
						}
					}

				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (arr[i][j] > 0)
					{
						arr[i][j] -= adj[i][j];
						if (arr[i][j] < 0)
							arr[i][j] = 0;

					}
					//cout << arr[i][j] << " ";
				}
				//cout << endl;
			}
			year++;
		}
	}

	if (cnt < 1)
		year = 0;

	cout << year;

	return 0;
}