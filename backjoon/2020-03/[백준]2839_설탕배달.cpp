#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10000000;

int main()
{
	int n;
	bool flag = false;
	int result = MAX;
	cin >> n;
		for (int i = 0; i <= n / 3; i++)
		{
			for (int j = 0; j <= n / 5; j++)
			{
				if ((3 * i) + (5 * j) == n)
				{
					if (result > (i + j))
						result = i + j;
				}
				else if ((3 * i) + (5 * j) > n)
					break;
			}
		}

		if (result== MAX)
			cout << -1<<"\n";
		else
			cout << result;
	return 0;
}