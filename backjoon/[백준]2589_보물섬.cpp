#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
	int xpos;
	int ypos;
};
queue<Point>q;

int m,n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char arr[110][110];
bool visited[110][110] = { false, };
int value_arr[110][110] = { 0, };

//int cnt = 0;
int max_cnt = -1;

void bfs(int i, int j)
{
	q.push({ i,j });
	visited[i][j] = true;
	while (!q.empty())
	{
		int qf_x = q.front().xpos;
		int qf_y = q.front().ypos;
		for (int t = 0; t < 4; t++)
		{
			int xp = qf_x + dx[t];
			int yp = qf_y + dy[t];
			if (arr[xp][yp] == 'L' && !visited[xp][yp])
			{
				visited[xp][yp] = true;
				q.push({ xp,yp });
				value_arr[xp][yp]=value_arr[qf_x][qf_y]+ 1;
				if (max_cnt < value_arr[xp][yp])
					max_cnt = value_arr[xp][yp];
			}
		}
		q.pop();
	}
	
}


int main()
{
	cin >> m>>n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'L' && !visited[i][j])
			{
				bfs(i, j);
			}
			memset(visited, false, sizeof(visited));
			memset(value_arr, 0, sizeof(value_arr));
		}
	}

	cout << max_cnt<<" ";

	return 0;
}