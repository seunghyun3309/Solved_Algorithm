#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n;
int cnt = 0;
int max_arr = -1;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool check[101][101] = { false, };
int arr[101][101];
int result[101] = { 0, };

int x_pos, y_pos;
struct depth
{
	int xpos;
	int ypos;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue <depth> q;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (max_arr < arr[i][j])
			{
				max_arr = arr[i][j];
			}
		}
	}

	for (int k = 1; k < max_arr; k++)
	{
		cnt = 0;
		memset(check, false, sizeof(check));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!check[i][j] && arr[i][j] > k)
				{
					cnt++;
					check[i][j] = true;
					q.push({ i,j }); // 구조체에서 큐 삽입

					while (!q.empty())
					{
						int x_cnt = q.front().xpos;
						int y_cnt = q.front().ypos;

						for (int m = 0; m < 4; m++)
						{
							x_pos = x_cnt + dx[m];
							y_pos = y_cnt + dy[m];
							if (!check[x_pos][y_pos] && x_pos < n && y_pos<n
								&& x_pos >= 0 && y_pos >= 0
								&& arr[x_pos][y_pos] > k)
							{
								check[x_pos][y_pos] = true;
								q.push({ x_pos, y_pos });
							}
						}
						q.pop();
					}
				}
			}
		}
		result[k] = cnt;
	}

	int result_num = 1;
	for (int i = 1; i <= max_arr; i++)
	{
		//cout << "result[" << i << "]" << result[i] << endl;
		if (result_num < result[i])
			result_num = result[i];
		//cout << endl;
	}
	cout << result_num;
	return 0;
}