#include <iostream>
#include <vector>
using namespace std;

int n;
long getMax = -99999999;
char express[21];
vector<int> number;
vector<char> op;

int calculate(long a, long b, char c)
{
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else if (c == '*')
		return a * b;
}

void function(int idx, long cnt)//idx는 계산횟수
{
	if (idx >= n / 2)
	{
		if (getMax < cnt)
			getMax = cnt;
		return;
	}
	else
	{
		long cur_result = calculate(cnt, number[idx + 1], op[idx]);
		function(idx + 1, cur_result);
		if (idx + 1 < n / 2)
		{
			long next = calculate(number[idx + 1], number[idx + 2], op[idx + 1]);
			long cur_Result = calculate(cnt, next, op[idx]);
			function(idx + 2, cur_Result);
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> express[i];
		if (i % 2 == 0)
		{
			number.push_back(express[i] - '0');
		}
		else
		{
			op.push_back(express[i]);
		}
	}
	function(0, number[0]);
	cout << getMax;
	return 0;
}