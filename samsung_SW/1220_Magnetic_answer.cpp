#include <iostream>

using namespace std;

const int MAX = 100;

int arr[MAX][MAX] = { 0, };
int main()
{
	for (int tc = 1; tc <= 10; tc++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}


		int count = 0;

		for (int j = 0; j < n;j++)
		{
			bool check = false;
			for (int i = 0; i < n; i++)
			{
				if (arr[i][j] == 0)
					continue;
				else if (check == 0 && arr[i][j] == 2) // 그냥 위로 갈 수 있는 경우 pass
					continue;
				else if (check == 1 && arr[i][j] == 2) // N극으로 막힌 경우
				{
					count++;
					check = 0;
				}
				else if(arr[i][j]==1) //S극이 있는 경우
				{
					check = 1;
				}
			}
		}

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << endl;
		//}


			cout << "#" << tc << " " << count << endl;
	}
	return 0;
}