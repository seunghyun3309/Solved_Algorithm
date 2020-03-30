#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20000010;
int arr[MAX];
int cnt[MAX] = { 0, };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cnt[arr[i] + 10000000]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		cout << cnt[num + 10000000] << " ";
	}
	return 0;
}