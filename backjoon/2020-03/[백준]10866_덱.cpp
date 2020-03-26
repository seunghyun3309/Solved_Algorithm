#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string str;
	deque<int>q;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push_front")
		{
			int k;
			cin >> k;
			q.push_front(k);
		}
		else if (str == "push_back")
		{
			int k;
			cin >> k;
			q.push_back(k);
		}
		else if (str == "pop_front")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
			{
				cout << q.back() << "\n";
				q.pop_back();
			}
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			if (q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (str == "front")
		{
			if (!q.empty())
				cout << q.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (str == "back")
		{
			if (!q.empty())
				cout << q.back() << "\n";
			else
				cout << -1 << "\n";
		}
		//push pop size empty front back
	}
	return 0;
}
