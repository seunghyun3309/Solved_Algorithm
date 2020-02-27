#include <iostream>

using namespace std;
int n;
const int MAX_NUM = 1000000000;
long long int  sum_n = 0;
long long int dp[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	//dp[m][n] : m번째에 n개가 들어 갈 수 있어
	for (int i = 0; i <= 9; i++)
	{
		if (i > 0)
			dp[1][i] = 1;
		else
			dp[1][i] = 0;
	} //dp[2]를 정의
	if (n >= 2)
	{
		for (int k = 2; k <= n; k++)
		{
			for (int i = 0; i <= 9; i++)
			{
				if (i == 0)
				{
					dp[k][i] = dp[k - 1][i + 1];
				}
				else if (i == 9)
				{
					dp[k][i] = dp[k - 1][i - 1];
				}
				else
				{
					dp[k][i] = (dp[k - 1][i - 1] + dp[k - 1][i + 1])%MAX_NUM;
				}
			}
		}
	}

	for (int m = 0; m <= 9; m++)
	{
		//cout << dp[n][m] << " ";
		sum_n += dp[n][m];
	}
	//cout << endl;

	sum_n %= MAX_NUM;
	cout << sum_n;


	return 0;
}