#include <iostream>
using namespace std;
bool Graph[1010][1010] = { false, };
bool visited[1010] = { false, };
int n, m;
int rst = 0;

void dfs(int k)
{
	visited[k] = true;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i] && Graph[k][i])
			dfs(i);
	}
}
//
//void bfs()
//{
//	visited[i] = true;
//	q.push(i);
//	while (!q.empty())
//	{
//		int t = q.front();
//		for (int k = 1; k <= n; k++)
//		{
//			if (!visited[k] && Graph[k][t])
//			{
//				visited[k] = true;
//				q.push(k);
//			}
//		}
//		q.pop();
//}

int main()
{
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		Graph[a][b] = true;
		Graph[b][a] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (!visited[i] && Graph[i][j])
			{
				rst++;
				dfs(i);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			rst++;
		}
	}
	cout << rst;
	return 0;
}