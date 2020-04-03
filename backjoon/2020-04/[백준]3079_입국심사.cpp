#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long  n, m;
long long arr[1000010];
long long k = 0;
int main()
{
	cin >> n >> m;
	for (long long i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long start = 0;
	long long end = m * arr[n - 1];

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long sum_arr = 0;
		for (long long i = 0; i < n; i++)
		{
			sum_arr += mid/arr[i];
		}
		if (sum_arr >= m) //성공
		{
			k = mid;
			end = mid - 1;//더 작은 범위
		}
		else //실패
		{
			start = mid + 1;//더 큰 범위
		}
	}
	cout << k;
}