#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int number[100] = { 0, };
int n;
bool flag = false;

bool check(int k)
{
	int len = 1;

	while (len <= k / 2)
	{
		bool good = false;
		for (int j = 0; j < len; j++)
		{
			if (number[k - j-1] != number[k - len - j-1])// 다르면 좋은 수열
				good = true;
		}
		if (!good)
			return false;
		else
			len++;
	}
	return true;
}

void recursion(int k)
{
	if (flag) return;
	if (check(k))
	{
		if (n == k)
		{
			for (int i = 0; i < k; i++)
			{
				cout << number[i];
			}
			flag = true;
			return ;
		}
		else
		{
			for (int m = 1; m <= 3; m++)
			{
				number[k] = m;
				recursion(k + 1);
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	recursion(0);

	return 0;
}