#include <iostream>

using namespace std;
int n;
long long int dp[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 100; i++) {

		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];

	return 0;
}