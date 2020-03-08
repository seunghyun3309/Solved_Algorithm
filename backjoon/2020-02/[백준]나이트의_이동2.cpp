#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
int n;
int x, y;
int rpos_x, rpos_y;
bool check[301][301] = { false, };
int move_cnt = 0;
int dx[8] = { -1,1,2,2,-1,1,-2,-2 };
int dy[8] = { 2,2,-1,1,-2,-2,-1,1 };
int x_cnt, y_cnt;

struct pos {
	int xpos;
	int ypos;
};

queue<pos> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		memset(check, false, sizeof(check));
		move_cnt = 0;
		cin >> n;
		cin >> x >> y;
		cin >> rpos_x >> rpos_y;

		q.push({ x,y });
		check[x][y] = true;

		while (!q.empty())
		{
			int len = q.size();
			while (len--)
			{
				int nx = q.front().xpos;
				int ny = q.front().ypos;
				q.pop();
				if (nx == rpos_x && ny == rpos_y)
				{
					cout << move_cnt << "\n";
					break;
				}
				for (int j = 0; j < 8; j++)
				{

					x_cnt = nx + dx[j];
					y_cnt = ny + dy[j];

					if (!check[x_cnt][y_cnt] && x_cnt >= 0 && x_cnt < n && y_cnt >= 0 && y_cnt < n)
					{
						q.push({ x_cnt,y_cnt });
						check[x_cnt][y_cnt] = true;
					}
				}
			}
			move_cnt++;
		}
		while (!q.empty())
			q.pop();
	}


	return 0;
}