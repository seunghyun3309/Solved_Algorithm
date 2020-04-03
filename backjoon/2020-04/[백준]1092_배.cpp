#include<iostream>
#include <algorithm>
using namespace std;

int n, m;
int crain[101];
int box[10010];
int load = 0;
int cnt = 0;

bool comp(int n1, int n2)
{
	if (n1 <= n2)
		return false;
	else
		return true;
}

int main()
{
	bool check[10010] = { false, };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> crain[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> box[i];
	}

	sort(crain, crain + n, comp);
	sort(box, box + m, comp);
	if (box[0] > crain[0])
	{
		cout << -1;
		return 0;
	}
	while (1)
	{
		int i = 0;
		int j = 0;
		while (i <= n)
		{
			if (!check[j]&&crain[i] >= box[j])
			{
				check[j] = true;
				i++;
				j++;
				load++;
			}
			else
			{
				j++;
			}
			if (j >= m)
				break;
		}
		cnt++;
		if (load == m)
			break;
	}
	cout << cnt;
}