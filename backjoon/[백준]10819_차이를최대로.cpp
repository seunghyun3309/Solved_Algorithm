#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
int num_arr[8];
bool visited[8];
int getSum = 0;
int getMax = -1;
vector<int>v;

void dfs(int k)
{
	if (k == n)
	{
		if (getMax < getSum)
			getMax = getSum;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				v.push_back(num_arr[i]);
				if (k >= 1)
				getSum += abs(v[k-1] - v[k]);
				dfs(k + 1);
				if (k >= 1)
					getSum -= abs(v[k-1] - v[k]);
				v.pop_back();
				visited[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num_arr[i];
	}
	dfs(0);
	cout << getMax;
	return 0;
}