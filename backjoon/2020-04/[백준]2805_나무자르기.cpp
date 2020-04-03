#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[1000010];
int k = 0;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long start = 1;
	long long end = arr[n - 1];

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long sum_arr = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >= mid)
				sum_arr += arr[i] - mid;
		}
		if (sum_arr >= m)
		{
			k = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << k;
}