#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;
int r, c, d;
int k;
int rst = 0;
int arr[101][101];
bool check[101][101] = { false, };
bool flag = false;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


struct pos {
	int xpos;
	int ypos;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cin >> r >> c >> d; //r은 가로좌표, c는 세로좌표, d는 방향좌표
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	queue<pos> q;
	q.push({ r,c });
	check[r][c] = true;
	int d_cnt = d;
	rst++;
	while (!q.empty())
	{
		k = 4; //횟수
		flag = false;
		while(k>0)
		{
			d_cnt--;
			if (d_cnt < 0)
				d_cnt = 3;
			int x_cnt = q.front().xpos + dx[d_cnt];
			int y_cnt = q.front().ypos + dy[d_cnt];
			if (arr[x_cnt][y_cnt] == 0&&!check[x_cnt][y_cnt]&&x_cnt>=0&&x_cnt<n
				&&y_cnt>=0&&y_cnt<m)
			{
				flag = true;
				q.push({ x_cnt, y_cnt });
				check[x_cnt][y_cnt] = true;
				rst++;
			}
			
			k--;
			if (flag)
				break;
		}
		if (!flag)
		{
			int x_cnt = q.front().xpos - dx[d_cnt];
			int y_cnt = q.front().ypos - dy[d_cnt];
			if (arr[x_cnt][y_cnt] == 0&& x_cnt >= 0 && x_cnt < n
				&& y_cnt >= 0 && y_cnt < m)
			{
				q.push({ x_cnt,y_cnt });
				/*if (!check[x_cnt][y_cnt])
				{
					check[x_cnt][y_cnt] = true;
					rst++;
				}*/
			}

			else
				break;
		}
		q.pop();
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << check[i][j]<<" ";
		}
		cout << endl;
	}*/
	cout << rst;
	return 0;
}