#include <iostream>
#include <algorithm>

long long n, k;
long long arr[1000010];
long long result = 0;
using namespace std;

int main()
{
	cin >> n >> k;
	for (long long  i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long start = 1;
	long long end = arr[n - 1];
	while (start <= end)
	{
		long long  mid = (start + end) / 2;
		long long sum_arr = 0;
		for (long long i = 0; i < n; i++)
		{
			sum_arr += arr[i]/mid;
		}
		if (sum_arr >= k)
		{
			result = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << result;
	return 0;
}