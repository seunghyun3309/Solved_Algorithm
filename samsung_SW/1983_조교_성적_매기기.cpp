#include <iostream>
using namespace std;

int main()
{
	int n, k;
	string rank_score[10] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };

	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{

		double total[100] = { 0, };
		int a, b, c;

		cin >> n >> k;

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >>c;
			total[i] = a * 0.35 + b * 0.45 + c * 0.2;
		}

		int r = 1;
		for (int i = 0; i < n; i++)
		{
			if (total[k-1] < total[i])
			{
				r++;
			}
		}

		int rank_cnt = n / 10;
		int result = 0;

		while (r > rank_cnt)
		{
			result++;
			rank_cnt += n / 10;
		}
		
		cout << "#" << tc << " " << rank_score[result] << endl;
	}
	return 0;
}