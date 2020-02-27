#include <iostream>
using namespace std;

int main()
{
	int bill[8] = { 50000,10000,5000,1000,500,100,50,10 };

	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		int result[8] = { 0, };
		int n;
		cin >> n;
		for (int i = 0; i < 8; i++)
		{
			while (bill[i] <= n)
			{
				n -= bill[i];
				result[i]++;
			}
		}


		cout << "#" << tc << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << result[i]<<" ";
		}
		cout << endl;
	}
	return 0;
}