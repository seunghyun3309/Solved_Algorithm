#include <iostream>
using namespace std;

int main()
{
	int arr[16][16] = { 0, };

	int n, k;
	int count = 0;
	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		int result[15] = { 0, };
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			count = 0;
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 1)
				{
					count++;
				}
				if (arr[i][j] == 0 && count != 0)
				{
					result[count]++;
					count = 0;
				}
				if (j == n - 1 && count != 0)
				{
					result[count]++;
					count = 0;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			count = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i][j] == 1)
				{
					count++;
				}
				if (arr[i][j] == 0 && count != 0)
				{
					result[count]++;
					count = 0;
				}
				if (i == n - 1 && count != 0)
				{
					result[count]++;
					count = 0;
				}
			}
		}
		cout << "#" << tc << " " << result[k] << endl;
	}
	return 0;
}