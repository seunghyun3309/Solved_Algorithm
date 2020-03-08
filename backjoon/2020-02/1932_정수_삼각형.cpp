#include <iostream>

using namespace std;
int n, k;
const int MAX = 1010;
int dp[MAX][MAX];

int dp_max(int x1, int x2)
{
	if (x1 < x2)
		return x2;
	else
		return x1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cin >> dp[i][j];//dp[0][1]...
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i][j] += dp_max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	int max_result = dp[n][0];
	for (int i = 1; i < n; i++)
	{
		//cout << dp[n][i] << endl;
		if (dp[n][i] > max_result)
			max_result = dp[n][i];
	}
	cout << max_result;
	return 0;
}