#include <iostream>
#include <vector>
using namespace std;

int n, m, v; //n은 컴퓨터 수 m은 연결수 v는 시작점
int x, y;
int cnt = 0;
bool Graph[101][101] = { false, };
bool check[101] = { false, };

void dfs(int idx)
{
	check[idx] = true;
	cnt++;
	for (int i = 1; i <= n; i++)
	{
		if (Graph[idx][i] == true && check[i] == false)
		{
			dfs(i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m ;
	for (int i = 1; i <= m; i++) //간선이 m개
	{
		cin >> x >> y;
		Graph[x][y] = true;
		Graph[y][x] = true;
	}

	dfs(1);
	cout << cnt-1;

	return 0;
}

