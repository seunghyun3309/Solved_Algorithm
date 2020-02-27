#include <iostream>

using namespace std;

int n;
int num;
int cnt = 0;
int num_cnt = 0;
const long long int MAX_NUM = 100000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < MAX_NUM; i++)
	{
		num = i;
		cnt = 0;
		while (num > 0)
		{
			if (num % 10 == 6)
				cnt++;
			else
				cnt = 0;
			if (cnt == 3)
			{
				num_cnt++;
				break;
			}
			num /= 10;
		}
		if (num_cnt == n)
		{
			cout << i;
			break;
		}
	}

	return 0;
}