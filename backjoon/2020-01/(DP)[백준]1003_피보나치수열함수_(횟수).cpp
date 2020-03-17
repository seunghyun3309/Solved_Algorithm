#include <iostream>

using namespace std;
int n,k;
long long int dp[2][51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[0][0] = 1;
	dp[0][1] = dp[1][0];
	
	for (int i = 2; i <= 50; i++) {

		dp[1][i] = dp[1][i - 1]+dp[1][i - 2];
		dp[0][i] = dp[1][i - 1];
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		cout << dp[0][k] << " " << dp[1][k]<<"\n";
	}

	return 0;
}