#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k;
string cmd;
int stack_data[10010];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int s_size = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> k;
			stack_data[s_size++] = k;
		}
		else if (cmd == "pop")
		{
			if (s_size == 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << stack_data[s_size - 1] << "\n";
				stack_data[s_size - 1] = 0;
				s_size--;
			}

		}
		else if (cmd == "size")
		{
			cout << s_size << "\n";
		}
		else if (cmd == "empty")
		{
			if (s_size == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (cmd == "top")
		{
			if (s_size == 0)
				cout << -1 << "\n";
			else
			{
				cout << stack_data[s_size - 1] << "\n";
			}

		}
	}

	return 0;
}