#include <iostream>

using namespace std;

int n;
int fibonnaci(int num)
{

	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
	{
		return fibonnaci(num - 1) + fibonnaci(num - 2);
	}
}

int main()
{
	cin >> n;

	cout << fibonnaci(n);

	return 0;
}