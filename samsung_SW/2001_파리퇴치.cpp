#include <iostream>

using namespace std;

int arr[10][10];
int n;

int main()
{
	
	int testcase;
	cin >> testcase;
	int n, m;
	

	int arr[15][15];

	for(int tc=1;tc<=testcase;tc++)
	{
		int max = 0;
		int x_cnt;
		int y_cnt;

		cin >> n >>m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (x_cnt = 0; x_cnt <= n-m ; x_cnt++)
		{
			for (y_cnt = 0; y_cnt <= n - m ; y_cnt++)
			{
				int result = 0;
				for (int i = x_cnt; i < x_cnt + m; i++)
				{
					for (int j = y_cnt; j < y_cnt + m; j++)
					{
						result += arr[i][j];
					}
				}

				if (max < result)
					max = result;

				
			}
		}
		
		cout << "#" << tc << " "<< max << endl;
	}

	return 0;
}