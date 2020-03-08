#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int cnt = 0;
int arr[11]; //n<=10

bool comp(int b1, int b2)
{
	if (b1 < b2)
		return false;
	else
		return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, comp);

	int m = 0;
	int sum = 0;
	while (sum < k)
	{
		if (arr[m] <= k - sum)
		{
			sum += arr[m];
			cnt++;
			if (sum == k)
				break;
		}
		else
		{
			m++;
		}
	}
	cout << cnt;
	return 0;
}