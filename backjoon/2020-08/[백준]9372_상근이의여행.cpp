#include <iostream>
using namespace std;
int n, m;
int parent[1010];
int a, b;
int connected;
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

	int testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++)
	{
		connected = 0; //연결된 수
		cin >> n;// 국가의 수
		cin >> m;//연결 횟수
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			if (findU(parent[a]) != findU(parent[b])) //부모가 다르면 연결하고 부모를 같게 만들어
			{
				connected++;
				unionU(a, b);
			}
		}

		cout << connected << "\n";
	}
    
	return 0;
}