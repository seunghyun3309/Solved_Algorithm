#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m, n; //지도 크기
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };
int arr[101][101]; //지도
int cal[101][101][5] = { 0, };//계산
bool visit[101][101][5] = { false, };
struct Point {
	int xpos;
	int ypos;
	int direc;
};
Point s;
Point e;
queue<Point>q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> s.xpos >> s.ypos >> s.direc;
	cin >> e.xpos >> e.ypos >> e.direc;

	q.push({ s.xpos, s.ypos, s.direc });
	visit[s.xpos][s.ypos][s.direc] = true;
	cal[s.xpos][s.ypos][s.direc] = 0;

	while (!q.empty())
	{
		int nx = q.front().xpos;
		int ny = q.front().ypos;
		int nd = q.front().direc;
		q.pop();
		//cout << nx << " "<<ny << " " << nd << " "<<cal[nx][ny][nd]<<endl;

		if (nx == e.xpos && ny == e.ypos && nd == e.direc)
		{
			cout << cal[e.xpos][e.ypos][e.direc];
			return 0;
		}

		for (int t = 1; t <= 3; t++)
		{
			int mx = nx + dx[nd] * t;
			int my = ny + dy[nd] * t;
			if (arr[mx][my] == 0 && mx >= 1 && mx <= m && my >= 1 && my <= n)
			{
				if (!visit[mx][my][nd])
				{
					visit[mx][my][nd] = true;
					q.push({ mx,my,nd });
					cal[mx][my][nd] = cal[nx][ny][nd] + 1;
				}
			}
			else
				break;
		}


		if (nd == 3 || nd == 4)
		{
			if (!visit[nx][ny][1])
			{
				visit[nx][ny][1] = true;
				q.push({ nx,ny,1 });
				cal[nx][ny][1] = cal[nx][ny][nd] + 1;
			}
			if (!visit[nx][ny][2])
			{
				visit[nx][ny][2] = true;
				q.push({ nx,ny,2 });
				cal[nx][ny][2] = cal[nx][ny][nd] + 1;
			}

		}
		if (nd == 1 || nd == 2)
		{
			if (!visit[nx][ny][3])
			{
				visit[nx][ny][3] = true;
				q.push({ nx,ny,3 });
				cal[nx][ny][3] = cal[nx][ny][nd] + 1;
			}
			if (!visit[nx][ny][4])
			{
				visit[nx][ny][4] = true;
				q.push({ nx,ny,4 });
				cal[nx][ny][4] = cal[nx][ny][nd] + 1;
			}
		}
	}

	return 0;
}