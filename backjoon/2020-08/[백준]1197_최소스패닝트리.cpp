#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int parent[100010];
int a, b, c;
int v, e; //정점의 개수, 간선의 개수
int connected=0;
int result = 0;


struct Graph {
	int x;
	int y;
	int weigh;
};
Graph g[100010];

bool comp(Graph g1, Graph g2)
{
	return g1.weigh < g2.weigh;
}


int findU(int x)
{
	if (x == parent[x])
		return x;
	else
	{
		return parent[x] = findU(parent[x]);
	}
}

void unionU(int x, int y)
{
	x = findU(x);
	y = findU(y);
	/*if (x < y)
		parent[x] = y;
	else if (x > y)*/
		parent[y] = x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c; // a와b 연결 가중치 c
		g[i] = { a,b,c };
	}
	sort(g, g + e, comp);

	for (int i = 0; i < e; i++)
	{
		if (findU(g[i].x) != findU(g[i].y))
		{
			connected++;
			result += g[i].weigh;
			unionU(g[i].x, g[i].y);

			if (connected == n - 1)
				break;
		}
	}

	cout << result;
	return 0;
}