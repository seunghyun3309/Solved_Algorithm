#include <iostream>
#include <algorithm>
#include<cstring>

using namespace std;

int R, C;
char arr[25][25];
int step[25][25];
bool visited[26] = { false, }; //알파벳순으로 출현했는지
int getMax = -1;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(int i, int j)
{
	if (step[i][j] > getMax)
		getMax = step[i][j];
	visited[arr[i][j] - 'A'] = true;
	for (int d = 0; d < 4; d++)
	{
		int x_cnt = i + dx[d];
		int y_cnt = j + dy[d];
		if (!visited[arr[x_cnt][y_cnt] - 'A']&&x_cnt>=0&&x_cnt<R&&y_cnt>=0&&y_cnt<C)
		{
			visited[arr[x_cnt][y_cnt] - 'A'] = true;
			step[x_cnt][y_cnt] = step[i][j] + 1;
			dfs(x_cnt, y_cnt);
			step[x_cnt][y_cnt] = 0;
			visited[arr[x_cnt][y_cnt] - 'A'] = false;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << getMax+1;
	return 0;
}