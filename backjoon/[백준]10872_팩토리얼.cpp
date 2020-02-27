#include <iostream>

using namespace std;

int len;
int n;
int result=1;

void dfs(int len)
{
	if (n == len)
	{
		result *= len;
		cout << result;
		return;
	}
	else
	{
		result *= len;
		dfs(len + 1);
	}
}

int main()
{
	cin >> n;
	if (n == 0)
		cout << 1;
	else
	{
		dfs(1);
	}

	return 0;
}