#include <iostream>
#include <algorithm>
using namespace std;

int arr[100010];

bool comp(int a, int b)
{
	if (a > b)
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n, comp);

	int max_weight = -1;
	for (int i = 1; i <= n; i++)
	{
		int weight = i * arr[i - 1];
		if (weight > max_weight)
		{
			max_weight = weight;
		}
	}

	cout << max_weight;
	return 0;
}
