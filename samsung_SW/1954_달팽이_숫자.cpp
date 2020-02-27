#include <iostream>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		int arr[10][10] = { 0, };
		int n;
		int num = 1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			arr[0][i] = num;
			num++;
		}
		int k=0;// 출발점
		int m = n - 1; //이동하는 수
		while (num <= n * n)
		{
			for (int i = 1; i <= m; i++)
			{
				arr[k + i][n - 1 - k] = num;
				num++;
			}
			for (int i = 1; i <=m; i++)
			{
				arr[n - 1 - k][n - 1- k - i] = num;
				num++;
			}
			m--;
			for (int i = 1; i <= m; i++)
			{
				arr[n-1-k-i][k] = num;
				num++;
			}
			for (int i = 1; i <=m; i++)
			{
				arr[k+1][k+i] = num;
				num++;
			}
			k++;
			m--;
		}
		

		cout << "#" << tc << " " << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << arr[i][j]<<" ";
			cout << endl;
		}

	}
	return 0;
}