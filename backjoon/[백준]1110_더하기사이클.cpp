#include <iostream>

int a, b, c, d, n;
int cycle = 1;
using namespace std;

int main()
{
	cin >> n;
	a = n / 10;
	b = n % 10;
	c = a + b;
	d = b*10 + (c%10);

	while (n != d)
	{
		//cout << d << endl;
		a = d / 10;
		b = d % 10;
		c = a + b;
		d = b * 10 + (c % 10);
		cycle++;
	}

	cout << cycle;
	return 0;
}