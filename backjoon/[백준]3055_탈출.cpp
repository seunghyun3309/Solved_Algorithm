#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;
int r, c;
char arr[101][101];
bool check[101][101] = { false, };
bool biber_flag = false;// 비버의 소굴
int move_cnt = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int g_xpos = 0, g_ypos = 0;
int d_xpos = 0, d_ypos = 0;
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

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				g_xpos = i;
				g_ypos = j;
			}
			if (arr[i][j] == 'D')
			{
				d_xpos = i;
				d_ypos = j;
			}
		}
	}
	q.push({ g_xpos,g_ypos });
	check[g_xpos][g_ypos] = true;

	while (!q.empty())
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == '*') //물 채우기
				{
					for (int d = 0; d < 4; d++)
					{
						x_cnt = i + dx[d];
						y_cnt = j + dy[d];
						if (arr[x_cnt][y_cnt] == '.' && x_cnt >= 0 && x_cnt < n && y_cnt >= 0 && y_cnt < m)
						{
							arr[x_cnt][y_cnt] = 'b';
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 'b')
					arr[i][j] = '*';
			}
		}
		if (biber_flag)
		{
			//biber_flag = true;
			break;
		}
		move_cnt++;
		int qs = q.size();
		for (int t = 0; t < qs; t++)
		{
			for (int d = 0; d < 4; d++)
			{
				x_cnt = q.front().xpos + dx[d];
				y_cnt = q.front().ypos + dy[d];
				if (arr[x_cnt][y_cnt] == '.' && !check[x_cnt][y_cnt] && x_cnt >= 0 && x_cnt < n && y_cnt >= 0 && y_cnt < m)
				{
					q.push({ x_cnt, y_cnt });
					check[x_cnt][y_cnt] = true;
				}
				else if (x_cnt == d_xpos && y_cnt == d_ypos)
				{
					q.push({ x_cnt,y_cnt });
					biber_flag = true;
					break;
				}
			}
			q.pop();
		}
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << endl;
		//}
	}

	if (biber_flag)
		cout << move_cnt;
	else
		cout << "KAKTUS";
	return 0;
}