#include <iostream>
using namespace std;

int main()
{
	int sdoku[9][9] = { 0, };
	bool line[10];
	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		bool result = true;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> sdoku[i][j];
			}
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				line[sdoku[i][j]]=true;
			}
			for (int k = 1; k <= 9; k++)
			{
				if (line[k] == false)
					result = false;
			}
			for (int i = 1; i <= 9; i++)
			{
				line[i] = false;
			}
		}
		for (int i = 0; i < 9; i++)
		{
		
			for (int j = 0; j < 9; j++)
			{

				line[sdoku[j][i]] = true;
			}
			for (int k = 1; k <= 9; k++)
			{
				if (line[k] == false)
					result = false;
			}
			for (int i = 1; i <= 9; i++)
			{
				line[i] = false;
			}
		}
		
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				
				for (int m = 3*i; m <= 3*i+2; m++)
				{
					for (int n = 3*j; n <= 3*j+2; n++)
					{
						line[sdoku[m][n]] = true;
					}
				}
				for (int k = 1; k <=9; k++)
				{
					if (line[k] == false)
						result = false;
				}
				for (int i = 1; i <= 9; i++)
				{
					line[i] = false;
				}
			}
		}

		cout << "#" << tc << " " << result << endl;
	}
	return 0;
}