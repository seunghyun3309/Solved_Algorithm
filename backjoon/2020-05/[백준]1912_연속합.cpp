#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int A[MAX];
//int ans = -999999;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int dp[MAX] = { -9999, };
    /*
    dp[i] 정의 : A[i]를 오른쪽 끝으로 하는 연속 부분 최대 합
    dp[i-1]은 i-1을 끝으로 하는 최대합이고 A[i]를 더하면 i를 끝으로 하는 최대합이 나오고
    A[i]와 비교하면 i를 끝으로 하는 최대합을 구할 수 있다
    */
	dp[0] = A[0];
	int ans = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(A[i], dp[i - 1] + A[i]);
		if (ans < dp[i])
		ans = dp[i];
	}
	cout << ans;
	return 0;
}