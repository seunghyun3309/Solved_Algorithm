#include <iostream>
#include <string>
#include <queue>
using namespace std;

int m, n, h;
int x, y, z;
int nx, ny, nz;

int Graph[101][101][101] = { 0, };
bool check[101][101][101] = { false, };

int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0, 1, 0, -1,0,0 };
int dz[6] = { 0,0,0,0,1,-1, };

bool all_tomato = false;
bool not_tomato = true;

int day = 0;
int duration;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> x_cnt;
	queue<int> y_cnt;
	queue<int>z_cnt;

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> Graph[i][j][k];

				if (Graph[i][j][k] == 0)
				{
					all_tomato = true;
				}
				else if (Graph[i][j][k] == 1)
				{
					check[i][j][k] = true;
					x_cnt.push(i);
					y_cnt.push(j);
					z_cnt.push(k);
				}
			}
		}
	}

	if (all_tomato == true)
	{
		day = 0; //익는 날짜
		while (!x_cnt.empty() && !y_cnt.empty() && !z_cnt.empty())
		{
			duration = x_cnt.size();
			for (int que = 0; que < duration; que++)
			{
				x = x_cnt.front();
				y = y_cnt.front();
				z = z_cnt.front();

				for (int p = 0; p < 6; p++)
				{
					int nx = x + dx[p];
					int ny = y + dy[p];
					int nz = z + dz[p];

					if (Graph[nx][ny][nz] == 0 && check[nx][ny][nz] == false
						&& nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h)
					{
						Graph[nx][ny][nz] = 1;
						check[nx][ny][nz] = true;
						x_cnt.push(nx);
						y_cnt.push(ny);
						z_cnt.push(nz);
					}
				}
				x_cnt.pop();
				y_cnt.pop();
				z_cnt.pop();
			}
			day++;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int k = 0; k < h; k++)
				{
					if (Graph[i][j][k] == 0) //익지 않은 토마토가 있는 경우
					{
						not_tomato = false;
						break;
					}
				}
			}
		}
		if (not_tomato == false)
		{
			cout << -1;
		}
		else
			cout << day - 1;
	}
	else //모든 토마토가 익어있는 경우
	{
		cout << 0;
	}
	return 0;
}

