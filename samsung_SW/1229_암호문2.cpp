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
		int cnt = 0;
		string cmd;
		cin >> origin;
		cnt = origin;
		for (int i = 0; i < origin; i++)
		{
			cin >> arr[i];
		}
		cin >> modify;
		for (int i = 0; i < modify; i++)
		{
			cin >> cmd >> x >> y;
			if (cmd == "I")
			{
				cnt += y;
				for (int i = cnt-1; i >= x; i--)
				{
					arr[y + i] = arr[i];
				}

				for (int j = x; j < x + y; j++)
				{
					cin >> arr[j];
				}
			}
			else if (cmd == "D")
			{
				cnt -= y;
				for (int i = x; i < cnt; i++)
				{
					arr[i] = arr[y+i];
				}

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