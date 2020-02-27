#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
bool Graph[1010][1010] = { false, };
bool visited[1010][1010] = { false, };
int m, n, k;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[10001] = { 0, };
int rst = 0;

struct Point {
	int xpos;
	int ypos;
};
queue<Point>q;
vector<int>v;
int bfs(int i, int j)
{
	visited[i][j] = true;
	q.push({ i,j });
	int cnt = 1;
	while (!q.empty())
	{
		int xpos = q.front().xpos;
		int ypos = q.front().ypos;
		for (int d = 0; d < 4; d++)
		{
			int xq = xpos + dx[d];
			int yq = ypos + dy[d];
			if (!visited[xq][yq] && !Graph[xq][yq] && xq >= 0 && xq < m && yq >= 0 && yq < n)
			{
				visited[xq][yq] = true;
				q.push({ xq,yq });
				cnt++;
			}
		}
		q.pop();
	}
	return cnt;
}

int main()
{
	int x1, y1, x2, y2;
	cin >> m >> n >> k; //m이 높이 n이 너비
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int a = y1; a < y2; a++)//높이가 y1과 y2에서부터
		{
			for (int b = x1; b < x2; b++) //의 너비
			{
				Graph[m - a - 1][b] = true;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && !Graph[i][j])
			{
				arr[rst++] = bfs(i,j);
			}
		}
	}
	sort(arr, arr + rst);
	cout << rst<<"\n";
	for (int i = 0; i < rst; i++)
	{
		cout << arr[i] << " ";
	}
	
	return 0;
}