#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
int cnt = 0;

char map[30];
int Graph[30][30] = {0, };
bool check[30][30] = { false, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> result;

void dfs(int x, int y)
{
	check[x][y] = true;
	cnt++;

	for (int m = 0; m < 4; m++)
	{
		if (Graph[x + dx[m]][y + dy[m]] == 1 && check[x + dx[m]][y + dy[m]] == false)
		{
			//check[x+dx[m]][y+dy[m]] = true;
			dfs(x + dx[m], y + dy[m]);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) //간선이 m개
	{
		cin >> map;
		for (int j = 0; j < n; j++)
		{
			Graph[i][j] = map[j] - '0';
		}
	}
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			if (Graph[i][j] == 1&&check[i][j]==false)
			{
				//check[i][j] = true;
				dfs(i, j);

				result.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}

