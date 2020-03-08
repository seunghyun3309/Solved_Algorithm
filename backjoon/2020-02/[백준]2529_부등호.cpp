#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int num[10];
char op[10];
bool visited[10] = { false, };
bool flag = false;
bool max_flag = false;
vector<int> v;
int max_arr[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
int min_arr[11] = { 10,10,10,10,10,10,10,10,10,10,10 };

void dfs(int len)
{
	if (flag)
		return;
	if (len == k+1)
	{
		for (int i = 0; i < k; i++)
		{
			if (op[i] == '<')
			{
				if (v[i] > v[i + 1])
					return;
			}
			else if (op[i] == '>')
			{
				if (v[i] < v[i + 1])
					return;
			}
		}
		flag = true;
		for (int i = 0; i < k + 1; i++)
		{
			cout << v[i];
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (!visited[i])
			{
				v.push_back(i);
				visited[i] = true;
				dfs(len + 1);
				visited[i] = false;
				v.pop_back();
			}
		}
	}
}

void dfs_max(int len)
{
	if (max_flag)
		return;
	if (len == k + 1)
	{
		for (int i = 0; i < k; i++)
		{
			if (op[i] == '<')
			{
				if (v[i] > v[i + 1])
					return;
			}
			else if (op[i] == '>')
			{
				if (v[i] < v[i + 1])
					return;
			}
		}
		max_flag = true;
		for (int i = 0; i < k + 1; i++)
		{
			cout << v[i];
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = 9; i >=0; i--)
		{
			if (!visited[i])
			{
				v.push_back(i);
				visited[i] = true;
				dfs_max(len + 1);
				visited[i] = false;
				v.pop_back();
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	for (int i = 0; i < 10; i++)
	{
		num[i] = i;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> op[i];
	}

	dfs_max(0);
	dfs(0);
	return 0;
}