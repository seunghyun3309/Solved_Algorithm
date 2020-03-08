#include <iostream>

using namespace std;

int n;
int cnt;
int arr[10010] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cnt;
		arr[cnt]++;
	}

	for (int i = 0; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++) //arr[i]값 번 반복
		{
			cout << i << "\n";
		}
	}

	return 0;
}