#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 1004000;
bool arr[1004000] = { false, };
int main()
{
	int n;
	cin >> n;

	arr[1] = true;
	//1. 소수인지 판별
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		for (int j = i * i; j <= MAX; j += i)
		{
			arr[j] = true;
		}
	}

	for (int i = n; i <= MAX; i++)
	{
		if (!arr[i])
		{
			bool decimal = true;
			stack<int>s;
			queue<int>q;

			int num = i;
			while (num > 0)
			{
				s.push(num % 10);
				q.push(num % 10);
				num /= 10;
			}
			while (!s.empty()&&!q.empty())
			{
				if (s.top() != q.front())
				{
					decimal = false;
				}
				s.pop();
				q.pop();
			}
			if (decimal == true)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
	
	return 0;
}