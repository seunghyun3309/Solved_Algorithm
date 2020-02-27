#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

int tall[9];
int tall_sum = 0;
bool visited[9] = { false, };
bool flag = false;


void dfs(int k)
{
	if (flag)
		return;
	if (k >= 2)
	{
		if (v[k - 2] > v[k - 1])return;
	}
	if (k == 7)
	{
		if (tall_sum == 100)
		{
			//sort(v.begin(), v.end());
			for (int j = 0; j < 7; j++)
			{
				cout << v[j] << "\n";
			}
			flag = true;
		}
		return;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (!visited[i])
			{
				tall_sum += tall[i];
				visited[i] = true;
				v.push_back(tall[i]);
				dfs(k + 1);
				v.pop_back();
				visited[i] = false;
				tall_sum -= tall[i];
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		cin >> tall[i];
	}
	dfs(0);

	return 0;
}