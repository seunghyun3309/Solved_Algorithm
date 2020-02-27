#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100000;

int main()
{
	for (int T = 1; T <= 10; T++)
	{
		int arr[MAX] = { 0, };
		int origin, modify;
		int x, y;
		string cmd;
		cin >> origin;
		for (int i = 0; i < origin; i++)
		{
			cin >> arr[i];
		}
		cin >> modify;
		for (int i = 0; i < modify; i++)
		{
			cin >> cmd >> x >> y;

				for (int i = origin-1; i >=x; i--)
				{
					arr[y+i] = arr[i];
				}

				for (int j = x; j < x + y; j++)
				{
					cin >> arr[j];
				}
		}

		cout << "#" << T <<" ";
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}