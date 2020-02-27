#include <iostream>

using namespace std;

int n;

int recursion(int num)
{
	if (num == 1)
		return 1;
	else
	{
		return 2 * recursion(num - 1) + 1;
	}
}

void order(int n, int begin, int end) //
{
	if (n == 0)
	{
		return;
	}
	else
	{
		order(n - 1, begin, 6 - begin - end); //n-1개를 1에서 3로 이동할때는 2, 1에서 2로 이동할 때는 3
		cout << begin << " " << end << "\n"; //
		order(n - 1, 6 - begin - end, end); //n-1개를 2로 이동했으면 3, 3으로 이동했으면 2
	}
}
int main()
{
	cin >> n;

	cout << recursion(n) << "\n";
	order(n, 1, 3);

	return 0;
}