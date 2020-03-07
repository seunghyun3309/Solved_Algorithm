#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int getMax = 0;
	int cnt = n;

	for (int i = 0; i < n; i++)
	{
		getMax += cnt * arr[i];
		cnt--;
	}

	cout << getMax;
	return 0;
}