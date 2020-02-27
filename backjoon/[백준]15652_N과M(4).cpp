#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[100];
bool check[100];
vector<int> result;
int len=0;

void dfs(int k)
{
	if (m == k)
	{
		for (int i = 0; i < result.size()-1; i++)
		{
			if (result[i] > result[i+1])
				return;
		}
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i]<<" ";
		}
		cout << "\n";
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
			{
				result.push_back(i);
				//check[i] = true;
				dfs(k + 1);
				result.pop_back();
				//check[i] = false;
			}
				
		}
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	dfs(0);

	return 0;
}