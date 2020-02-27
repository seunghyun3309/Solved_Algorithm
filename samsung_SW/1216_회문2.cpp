#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 100;
char arr[MAX][MAX];

int main()
{
	for (int tc = 1; tc <= 10; tc++)
	{
		int count = 0;

		int n;
		cin >> n;



		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				cin >> arr[i][j];
			}
		}
		
		int k;
		int max = 0;
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				k = 0;
				while (arr[i][j - k] == arr[i][j + k])
				{
					if (j - k >= 0 && j + k < 100)
						k++;
					else
						break;
				}
				if (2 * k - 1 > max)
				{
					max = 2 * k - 1;
				}
				k = 0;
				while (arr[i - k][j] == arr[i + k][j])
				{
					if (i - k >= 0 && i + k < 100)
						k++;
					else
						break;
				}

				if (2 * k - 1 > max)
				{
					max = 2 * k - 1;
				}
			}

			//짝수
			k = 0;
			for (int i = 0; i < MAX; i++)
			{
				for (int j = 0; j < MAX; j++)
				{
					k = 0;
					while (arr[i][j - k] == arr[i][j + 1 + k])
					{
						if (j - k >= 0 && j + 1 + k < 100)
							k++;
						else
							break;
					}
					if (2 * k  > max)
					{
						max = 2 * k ;
					}
					k = 0;
					while (arr[i - k][j] == arr[i + 1 + k][j])
					{
						if (i - k >= 0 && i + 1 + k < 100)
							k++;
						else
							break;
					}

					if (2 * k > max)
					{
						max = 2 * k;
					}
				}
			}
		}

	

		cout << "#" << tc << " " << max << endl;
	}

	return 0;
}