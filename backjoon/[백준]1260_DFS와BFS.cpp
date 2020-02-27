#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;

int n, m, v;
stack<int> s;
queue<int> q;
vector<int> list[MAX_N]; //인접리스트를 담는 배열

bool check[MAX_N] = { false, };


void dfs_graph(int idx)
{
	check[idx] = true;
	cout << idx << " ";
	for (int i = 0; i < list[idx].size(); i++)
	{
		if (check[list[idx][i]] == false)
		{
			dfs_graph(list[idx][i]);
		}
	}
}

void bfs(int idx)
{
	q.push(idx);
	check[idx] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout <<  x << " ";

		// list[x]인접 친구들을
		for (int i = 0; i < list[x].size(); i++)
		{
			if (check[list[x][i]] == false)
			{
				check[list[x][i]] = true;
				q.push(list[x][i]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		list[x].push_back(y);
		list[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(list[i].begin(), list[i].end());
	}

	//DFS
	dfs_graph(v);

	cout << "\n";
	//BFS
	for (int i = 1; i <= n; i++)
	{
		check[i] = { false, };
	}
	
	bfs(v);
	
}

