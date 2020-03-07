#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, L;
int arr[1010] = { 0, };
int cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> L;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n); //물 새는 위치 정렬

	int xpos = 0;
	int xpos_next = 0;
	while (1)
	{
		if (xpos_next >= n || xpos >= n)
		{
			cnt++;
			break;
		}

		if (arr[xpos_next] - arr[xpos] <= L - 1)
		{
			xpos_next++;
		}
		else
		{
			cnt++;
			xpos = xpos_next;
		}
	}

	cout << cnt;

	return 0;
}