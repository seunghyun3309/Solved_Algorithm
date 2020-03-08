#include <iostream>

using namespace std;
int n;
const int MAX = 1000001;
long long int dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= MAX-1; i++) {

		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= 15746;
	}

	cout << dp[n] << "\n";

	return 0;
}