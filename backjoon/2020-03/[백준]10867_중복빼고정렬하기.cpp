#include <iostream>
#include <algorithm>
using namespace std;

int arr[100010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	bool checked[100010] = { false, };
	for (int i = 0; i < n; i++)
	{
		if (!checked[arr[i]+1000])
		{
			checked[arr[i]+1000] = true;
			cout << arr[i] << " ";
		}
	}
	
	return 0;
}
