#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
	int xpos;
	int ypos;
};
queue<Point>q;

int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char arr[110][110];
bool visited[110][110] = { false, };

int cnt = 0;
void bfs_R(int i, int j)
{
	q.push({ i,j });
	visited[i][j] = true;
	while (!q.empty())
	{
		int xpos = q.front().xpos;
		int ypos = q.front().ypos;

		for (int t = 0; t < 4; t++)
		{
			int xp = q.front().xpos + dx[t];
			int yp = q.front().ypos + dy[t];
			if (!visited[xp][yp] && arr[xp][yp] == 'R')
			{
				if (xp >= 0 && xp < n && yp >= 0 && yp < n)
				{
					q.push({ xp,yp });
					visited[xp][yp] = true;
				}
			}
		}
		q.pop();
	}
}
void bfs_G(int i, int j)
{
	q.push({ i,j });
	visited[i][j] = true;
	while (!q.empty())
	{
		int xpos = q.front().xpos;
		int ypos = q.front().ypos;

		for (int t = 0; t < 4; t++)
		{
			int xp = q.front().xpos + dx[t];
			int yp = q.front().ypos + dy[t];
			if (!visited[xp][yp] && arr[xp][yp] == 'G')
			{
				if (xp >= 0 && xp < n && yp >= 0 && yp < n)
				{
					q.push({ xp,yp });
					visited[xp][yp] = true;
				}
			}
		}
		q.pop();
	}
}
void bfs_B(int i, int j)
{
	q.push({ i,j });
	visited[i][j] = true;
	while (!q.empty())
	{
		int xpos = q.front().xpos;
		int ypos = q.front().ypos;

		for (int t = 0; t < 4; t++)
		{
			int xp = q.front().xpos + dx[t];
			int yp = q.front().ypos + dy[t];
			if (!visited[xp][yp] && arr[xp][yp] == 'B')
			{
				if (xp >= 0 && xp < n && yp >= 0 && yp < n)
				{
					q.push({ xp,yp });
					visited[xp][yp] = true;
				}
			}
		}
		q.pop();
	}
}
void bfs_RG(int i, int j)
{
	q.push({ i,j });
	visited[i][j] = true;
	while (!q.empty())
	{
		int xpos = q.front().xpos;
		int ypos = q.front().ypos;

		for (int t = 0; t < 4; t++)
		{
			int xp = q.front().xpos + dx[t];
			int yp = q.front().ypos + dy[t];
			if (!visited[xp][yp])
			{
				if (arr[xp][yp] == 'G' || arr[xp][yp] == 'R')
				{
					if (xp >= 0 && xp < n && yp >= 0 && yp < n)
					{
						q.push({ xp,yp });
						visited[xp][yp] = true;
					}

				}
			}

		}
		q.pop();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'R' && !visited[i][j])
			{
				bfs_R(i, j);
				cnt++;
			}
			if (arr[i][j] == 'B' && !visited[i][j])
			{
				bfs_B(i, j);
				cnt++;

			}
			if (arr[i][j] == 'G' && !visited[i][j])
			{
				bfs_G(i, j);
				cnt++;

			}
		}
	}

	cout << cnt<<" ";

	cnt = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				if (arr[i][j] == 'R' || arr[i][j] == 'G')
				{
					bfs_RG(i, j);
					cnt++;
				}
				
			}
			
			if (arr[i][j] == 'B' && !visited[i][j])
			{
				bfs_B(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}