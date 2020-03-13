#include <iostream>
#include <algorithm>
int num[100010];
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];

	}
	sort(num, num + n);
	// 0 1 2 3 4 5 6 7 8 n=9 idx=2
	 double kmzh = n - 1;
	kmzh/= (double)(k - 1);
	int cnt;
	cnt = ceil(kmzh);
	cout << cnt;
	return 0;
}