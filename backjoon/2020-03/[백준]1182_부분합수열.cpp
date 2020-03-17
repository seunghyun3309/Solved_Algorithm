#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s;
int arr[21];
int cnt = 0;
bool check[21] = { false, };
vector<int>v;

void dfs(int sum, int num)
{
	if (num >= 2)//2개 이상 있는 경우
	{
		if (v[num - 2] > v[num-1])//v[0]보다 v[1]이 커야ㅡ함
			return;
	}


	if (num > n)
	{
		return;
	}

	if (num!=0&&sum == s)
	{
		cnt++;
	}

	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			v.push_back(i);
			dfs(sum + arr[i], num + 1);
			v.pop_back();
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	dfs(0, 0);
	cout << cnt;
	return 0;
}