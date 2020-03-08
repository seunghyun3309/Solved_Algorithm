#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n;
int x, y;
int rpos_x, rpos_y;
int check[301][301] = { 0, };
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
		if (!q.empty())
			q.pop();

		cin >> n;
		cin >> x >> y;
		cin >> rpos_x >> rpos_y;
		q.push({ x,y });
		check[x][y] = 0;
		if (x == rpos_x && y == rpos_y)
			check[rpos_x][rpos_y] = 0;
		else
		{
			while (!q.empty())
			{

				for (int j = 0; j < 8; j++)
				{
					x_cnt = q.front().xpos + dx[j];
					y_cnt = q.front().ypos + dy[j];

					if (check[x_cnt][y_cnt] == 0 && x_cnt >= 0 && x_cnt < n && y_cnt >= 0 && y_cnt < n)
					{
						check[x_cnt][y_cnt] = check[q.front().xpos][q.front().ypos] + 1;
						q.push({ x_cnt,y_cnt });
					}


				}
				q.pop();
			}
		}
		cout << check[rpos_x][rpos_y] << "\n";
	}
	return 0;
}