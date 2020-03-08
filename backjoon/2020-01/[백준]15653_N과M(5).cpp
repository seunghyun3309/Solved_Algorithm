#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100];
bool check[100] = { false, };
int len = 0;
int n, m;
vector<int> result;

void dfs(int len)
{
	if (m == len) //길이가 m이면
	{
		/*for (int i = 0; i < result.size()-1; i++)
		{
			if (result[i] > result[i + 1])
				return;
		}*/
		for (int i = 0; i < result.size(); i++)
		{
			cout<< result[i]<<" ";
		}
		cout << "\n";
		return;
	}
	else
	{

		for (int i = 0; i < n; i++)
		{
			if (!check[i])
			{
				result.push_back(arr[i]);
				check[i] = true;
				dfs(len + 1);
				check[i] = false;
				result.pop_back();
			}
		}
	}
}
int main()
{
	cin >> n >> m; //n개의 자연수 길이가 m
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n);

	dfs(0);

	return 0;
}