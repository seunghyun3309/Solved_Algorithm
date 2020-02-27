#include <iostream>

using namespace std;

int arr[9][9];
bool row[9][9] = { false, };
bool col[9][9] = { false, };
bool square[9][9] = { false, };

void dfs(int total)
{
	int x_pos = total / 9;
	int y_pos = total % 9;

	if (total == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		//cout << "\n";
		exit(0);
	}
	if (arr[x_pos][y_pos] == 0)
	{
		for (int k = 1; k <= 9; k++)
		{
			if (row[x_pos][k] == false && col[y_pos][k] == false && square[(x_pos / 3) * 3 + (y_pos / 3)][k] == false)
			{
				row[x_pos][k] = true;
				col[y_pos][k] = true;
				square[(x_pos / 3) * 3 + (y_pos / 3)][k] = true;
				arr[x_pos][y_pos] = k;
				dfs(total + 1);
				arr[x_pos][y_pos] = 0;
				row[x_pos][k] = false;
				col[y_pos][k] = false;
				square[(x_pos / 3) * 3 + (y_pos / 3)][k] = false;
			}
		}
	}
	// 0부터 9까지 중에서 성립 하면 값을 입
	else
		dfs(total + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
			{
				row[i][arr[i][j]] = true;
				col[j][arr[i][j]] = true;
				square[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
			}
		}
	}
	dfs(0);

	return 0;
}