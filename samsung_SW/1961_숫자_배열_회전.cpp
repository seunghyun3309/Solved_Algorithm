#include <iostream>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		int n;
		cin >> n;
		int arr[7][7];
		int arr_90[7][7] = { 0, };
		int arr_180[7][7] = { 0, };
		int arr_270[7][7] = { 0, };

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr_90[i][j] = arr[n - j - 1][i];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr_180[i][j] = arr[n-i-1][n-j-1];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr_270[i][j] = arr[j][n-i-1];
			}
		}
		cout << "#" << tc << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << arr_90[i][j];
			cout << " ";
			for (int j = 0; j < n; j++)
				cout << arr_180[i][j];
			cout << " ";
			for (int j = 0; j < n; j++)
				cout << arr_270[i][j];
			cout << endl;
		}
		
	}
	return 0;
}