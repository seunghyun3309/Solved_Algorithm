#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
int S[50];
bool check[50] = { false, };
vector<int>result;
void dfs(int n, int idx)
{
	if (n == 6)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << result[j] << " ";
		}
		cout << "\n";
		return;
	}
	else
	{
		for (int i = idx; i < k; i++)
		{
			if (!check[i])
			{
				check[i] = true;
				result.push_back(S[i]);
				dfs(n + 1, i);
				result.pop_back();
				check[i] = false;
			}
		}
	}
}

int main()
{

	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		else
		{
			for (int i = 0; i < k; i++)
			{
				cin >> S[i];
			}
			dfs(0,0);
		}
		cout << "\n";
	}
	
}