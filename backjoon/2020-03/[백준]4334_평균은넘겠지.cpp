#include <iostream>
#include <cstring>
using namespace std;

double arr[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		int n;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		double average = 0;
		int over_average = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			average += arr[i];
		}

		average /= n;

		for (int i = 0; i < n; i++)
		{
			if (average < arr[i])
				over_average++;
		}
		double result = (double)over_average / n;
		cout << fixed;
		cout.precision(3);
		cout << result*100 << "%"<< endl;

	}
	
	return 0;

}
