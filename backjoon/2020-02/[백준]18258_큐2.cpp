#include <iostream>
#include <queue>

using namespace std;
int arr[2000001];
int n;
string cmd;
int size_q = 0;
int k;
int push_num = 0, pop_num = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> k;
			arr[push_num] = k;
			push_num++;
			size_q++;
		}
		if (cmd == "pop")
		{
			if (size_q == 0)
				cout << -1 << "\n";
			else
			{
				cout << arr[pop_num] << "\n";
				arr[pop_num] = 0;
				pop_num++;
				size_q--;
			}

		}
		if (cmd == "size")
		{
			cout << size_q << "\n";
		}
		if (cmd == "empty")
		{
			if (size_q > 0)
			{
				cout << 0 << "\n";
			}
			else
				cout << 1 << "\n";
		}
		if (cmd == "front")
		{
			if (size_q == 0)
				cout << -1 << "\n";
			else
				cout << arr[pop_num] << "\n";
		}
		if (cmd == "back")
		{
			if (size_q == 0)
				cout << -1 << "\n";
			else
				cout << arr[push_num - 1] << "\n";
		}
	}

	return 0;
}