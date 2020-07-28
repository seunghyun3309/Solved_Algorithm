#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int M, N;
int x, y;
int result = -1;
int temp;

int gcd(int n1, int n2)
{
	while (n2 != 0)
	{
		int r = n1 % n2;
		n1 = n2;
		n2 = r;
	}
	return n1;
}

int LCM(int n1, int n2)
{
	return n1 * n2 / gcd(n1, n2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		result = -1;
		cin >> M >> N >> x >> y; //1부터 M-1까지 

		int k = x;
		while (k <= LCM(M, N))
		{
			if (k % N == 0)
				temp = N;
			else
				temp = k%N;
			if (temp== y)
			{
				result = k;
				break;
			}
			k += M;
		}
		cout << result << "\n";
	}

	return 0;
}