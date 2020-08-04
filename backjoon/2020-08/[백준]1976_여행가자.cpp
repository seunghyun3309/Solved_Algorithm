#include <iostream>
using namespace std;
int n, m;
bool flag = true;
int map[1010][1010];
int parent[1010];
int a, b;
int path[1010];

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
	cin >> n;// 도시의 수
	cin >> m;//선택 도시의 수
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				unionU(i, j);
			}

		}
		//for (int i = 0; i <= n; i++)
		//{
		//	cout<< parent[i]<<" ";
		//}
		//cout << endl;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> path[i];
	}
	for (int k = 0; k < m - 1; k++)
	{
		if (findU(path[k]) != findU(path[k+1]))
		{
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}