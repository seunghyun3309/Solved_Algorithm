#include <iostream>

using namespace std;

int n;
int sum, num;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int i = 1;
	int result = 0;
	while (i < 1000000)
	{
		num = i;
		sum = num;
		while (num >= 1)
		{
			sum += num % 10;
			num /= 10;
		}

		if (sum == n)
		{
			result = i;
			break;
		}
		i++;
	}
	cout << result;
	return 0;
}