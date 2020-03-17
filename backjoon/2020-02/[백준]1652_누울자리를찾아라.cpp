#include <iostream>
#include <cstring>
using namespace std;
int n;
char arr[101][101];
bool check[101][101];
int col_num = 0;
int row_num = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	//row
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (!check[i][j] && arr[i][j] == '.' && arr[i][j + 1] == '.')
			{
				row_num++;
				check[i][j] = true;
				int k = 1;
				while (arr[i][j + k] == '.' && j + k < n)
				{
					check[i][j + k] = true;
					k++;
				}
			}

		}
	}
	//memset
	memset(check, false, sizeof(check));
	// col
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!check[i][j] && arr[i][j] == '.' && arr[i + 1][j] == '.')
			{
				col_num++;
				check[i][j] = true;
				int k = 1;
				while (arr[i + k][j] == '.' && i + k < n)
				{
					check[i + k][j] = true;
					k++;
				}
			}

		}
	}
	cout << row_num << " " << col_num;
	return 0;
}