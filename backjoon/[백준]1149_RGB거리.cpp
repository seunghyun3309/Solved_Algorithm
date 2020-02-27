#include <iostream>

using namespace std;
int n,k;
const int MAX = 1001;
int dp[MAX][3];

int dp_min(int x1, int x2, int x3)
{
	if (x1 > x2)
	{
		if (x2 > x3)
		{
			return x3;
		}
		else
		{
			return x2;
		}
	}
	else if (x1 > x3)
	{
		return x3;
	}
	else
		return x1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cin >> dp[0][0] >> dp[0][1] >> dp[0][2]; //dp[n번째열][칠하는 색깔] : 합
	int color[3];
	for (int i = 1; i < n; i++)
	{
		cin >> color[0] >> color[1] >> color[2];
		if (dp[i-1][1] + color[0] < dp[i - 1][2] + color[0])
		{
			dp[i][0] = dp[i - 1][1] + color[0];
		}
		else
		{
			dp[i][0] = dp[i - 1][2] + color[0];
		}
		if (dp[i - 1][0] + color[1] < dp[i - 1][2] + color[1])
		{
			dp[i][1] = dp[i - 1][0] + color[1];
		}
		else
		{
			dp[i][1] = dp[i - 1][2] + color[1];
		}
		if (dp[i - 1][0] + color[2] < dp[i - 1][1] + color[2])
		{
			dp[i][2] = dp[i - 1][0] + color[2];
		}
		else
		{
			dp[i][2] = dp[i - 1][1] + color[2];
		}
	}
	cout << dp_min(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]);
	return 0;
}