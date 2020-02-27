#include <iostream>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		int A,B,small,sum,diff;
		int small_arr[20] = { 0, };
		int big_arr[20] = { 0, };

		cin >> A >> B;

		if (A < B)
		{
			small = A;
			for (int i = 0; i < A; i++)
			{
				cin >> small_arr[i];
			}
			for (int i = 0; i < B; i++)
			{
				cin >> big_arr[i];
			}
			diff = B - A;
		}
		else
		{
			small = B;
			for (int i = 0; i < A; i++)
			{
				cin >> big_arr[i];
			}
			for (int i = 0; i < B; i++)
			{
				cin >> small_arr[i];
			}
			diff = A - B;
		}
		int max = -99999999;

		for (int i = 0; i <= diff; i++)
		{
			sum = 0;
			for (int j = 0; j < small; j++)
			{
				sum += small_arr[j] * big_arr[i + j]; //small은 무조건 0부터
			}
			if (max < sum)
			{
				max = sum;
			}
		}

		cout << "#" << tc << " " << max <<endl;

	}
	return 0;
}