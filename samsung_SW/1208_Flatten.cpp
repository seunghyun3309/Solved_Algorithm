#include <iostream>

using namespace std;

int main()
{

	int high[100];
	for (int T = 1; T <= 10; T++)
	{
		int n;
		cin >> n;
		int arr[100][100] = { 0, };

		for (int i = 0; i < 100; i++)
		{
			cin >> high[i];
			for (int j = 0; j < high[i]; j++)
			{
				arr[i][j] = 1;
			}
		}

		int minus = n;
		for (int j = 99; j >= 0; j--)
		{
			for (int i = 0; i < 100; i++)
			{
				if (minus > 0 && arr[i][j] == 1)
				{
					arr[i][j] = 0;
					minus--;
				}
			}
		}

		int plus = n;
		for (int j = 0; j < 100; j++)
		{
			for (int i= 0; i < 100; i++)
			{
				if (plus > 0 && arr[i][j] == 0)
				{
					arr[i][j] = 1;
					plus--;
				}
			}
		}

		int min_j;
		bool flag1 = false;
		for (int j = 0; j < 100; j++)
		{
			for (int i = 0; i < 100; i++)
			{
				if (arr[i][j] == 0 && flag1==false)
				{
					flag1 = true;
					min_j = j;
				}

			}
		}

		int max_j;
		bool flag2 = false;
		for (int j = 99; j >=0; j--)
		{
			for (int i = 0; i < 100; i++)
			{
				if (arr[i][j] == 1 && flag2 == false)
				{
					flag2 = true;
					max_j = j;
				}
			}
		}

		cout << "#" << T << " " << max_j - min_j+1<<endl; //높이가 
	}

	return 0;
}