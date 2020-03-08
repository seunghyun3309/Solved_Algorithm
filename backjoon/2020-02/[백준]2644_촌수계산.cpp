#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m; int a, b; int x, y;
const int MAX = 108;
bool Graph[MAX][MAX] = { false, };
bool check[MAX] = { false, };
int cheon[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> q;
	
	cin >> n;
	cin >> a >> b;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		Graph[x][y] = true;
		Graph[y][x] = true;
	}
	
	memset(cheon, -1, sizeof(cheon));

	check[a] = true;
	q.push(a); // 출발점은 시작
	cheon[a] = 0;

	while (!q.empty())
	{
		int t = q.front();
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == false && Graph[t][i]==true)
			{
				check[i] = true;
				q.push(i);
				cheon[i] = cheon[t] + 1;
			}
		}
		q.pop();
	}

	cout << cheon[b];
	return 0;
}