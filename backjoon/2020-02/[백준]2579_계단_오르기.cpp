#include <iostream>

using namespace std;
int n, k;
const int MAX = 1010;
int dp[MAX][3] = { 0, };

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
	for (int i = 0; i < n; i++)
	{
		cin >> dp[i][0];
	}
	dp[0][1] = dp[0][0];
	dp[1][1] = dp[1][0] + dp[0][0];
	dp[1][2] = dp[1][0];
	for (int j = 2; j < n; j++)
	{
		dp[j][1] = dp[j][0] + dp[j - 1][2];
		dp[j][2] = dp[j][0] + dp_max(dp[j - 2][1], dp[j - 2][2]);
	}
	//cout << endl;
	//for(int k=0;k<n;k++)
	//cout << dp[k][1] <<" "<< dp[k][2]<<endl;
	cout << dp_max(dp[n - 1][1], dp[n - 1][2]);

	return 0;
}