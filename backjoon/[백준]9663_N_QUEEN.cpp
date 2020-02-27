#include <iostream>

using namespace std;

const int MAX = 20;
int n;
int result = 0;
int y_pos[MAX] = { false, };
bool check(int idx)
{
	int k = 1;
	bool flag = true;

	while (k < idx && flag)//이전에 정해진 퀸
	{
		if (y_pos[idx] == y_pos[k] || abs(y_pos[idx] - y_pos[k]) == idx - k) //x_pos가 같거나 대각선에 위치
		{
			flag = false;
		}
		k++;
	}
	return flag;
}
void n_queen(int idx)
{
	if (check(idx))
	{
		if (idx == n)
			result++;
		else
		{
			for (int j = 0; j < n; j++)
			{
				y_pos[idx + 1] = j; //y_pos가 높이,  j가 x_pos
				n_queen(idx + 1);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	n_queen(0);

	cout << result;

	return 0;
}