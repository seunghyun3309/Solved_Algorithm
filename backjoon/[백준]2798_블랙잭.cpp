#include <iostream>
#include <vector>


using namespace std;

int n, m;
vector<int> result;
int arr[101] = { 0, };
bool check[101] = { false, };

int sum = 0;
int getMax = 0;

void dfs(int k)
{
	if (k == 3)
	{
		sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum += result[i];
		}
		if (sum <= m && getMax < sum)
		{
			getMax = sum;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!check[i])
			{
				result.push_back(arr[i]);
				check[i] = true;
				dfs(k + 1);
				check[i] = false;
				result.pop_back();
			}
		}
	}
}



int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dfs(0);
	cout << getMax;

	return 0;
}