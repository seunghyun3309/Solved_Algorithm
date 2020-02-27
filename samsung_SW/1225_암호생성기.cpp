#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100000;

int main()
{
	for (int T = 0; T < 10; T++)
	{
		int t;
		cin >> t;
		int arr[MAX] = { 0, };
		for (int i = 0; i < 8; i++)
		{
			cin >> arr[i];
		}

		int k=0;

		while (1)
		{
				arr[8 + k] = arr[k] - (k % 5 + 1);
				if (arr[8 + k] <= 0)
				{
					arr[8 + k] = 0;
					break;
				}
				else
					k++;
		}
		cout << "#" << t <<" ";
		for (int i = 0; i < 8; i++)
		{
			cout << arr[i+k+1] << " ";
		}
		cout << endl;
	}
	return 0;
}