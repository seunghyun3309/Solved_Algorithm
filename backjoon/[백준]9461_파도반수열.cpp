#include <iostream>

using namespace std;
int n,k;
const int MAX = 101;
long long int dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	for (int i = 4; i <= MAX-1; i++) {

		dp[i] = dp[i - 2] + dp[i - 3];
	}

	for (int j = 0; j < n; j++)
	{
		cin >> k;
		cout << dp[k] << "\n";
	}

	return 0;
}