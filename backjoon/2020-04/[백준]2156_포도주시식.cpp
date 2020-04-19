#include <iostream>
using namespace std;

int dp[10010];
int arr[10010];
int max_sum = 0;


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[0] = 0;
	dp[1] = arr[1];
	if (n > 1)
		dp[2] = arr[1] + arr[2]; //두번째는 두개 다 포함 한 곳이 최대
	for (int i = 3; i <= n; i++)
	{
		int temp[3]; //경우의 수를 세가지로 나눈다
		temp[0] = dp[i - 1]; // arr[i]를 포함하지 않는 경우
		temp[1] = dp[i - 2] + arr[i]; // arr[i-1]이 포함되지 않는 경우
		temp[2] = dp[i - 3] + arr[i - 1] + arr[i];// arr[i-2]가 포함되지 않는 경우
		dp[i] = temp[0];
		if (dp[i] < temp[1])
			dp[i] = temp[1];
		if (dp[i] < temp[2])
			dp[i] = temp[2];
	}

	cout << dp[n];
	return 0;
}
