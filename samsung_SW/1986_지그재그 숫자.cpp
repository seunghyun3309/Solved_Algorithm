#include <iostream>

using namespace std;

int n;
int result;

int main()
{
	int testcase;
	cin >> testcase;

	for(int tc=1;tc<=testcase;tc++)
	{
		cin >> n;
		if (n % 2 == 0)
		{
			result = n / 2;
			result *= -1;
		}
		else
		{
			result = (n + 1) / 2;
		}
		cout << "#" << tc << " "<< result << endl;
	}
    
	return 0;
}