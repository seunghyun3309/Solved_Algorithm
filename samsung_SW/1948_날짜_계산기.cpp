#include <iostream>
using namespace std;

int main()
{
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		int day=0;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		day = month[a] - b + 1;

		if(a==c)
			cout << "#" << tc << " " << day << endl;
		else
		{
			for (int k = a + 1; k < c; k++)
			{
				day += month[k];
			}
				day += d;

			cout << "#" << tc << " " << day << endl;
		}
	}
	return 0;
}