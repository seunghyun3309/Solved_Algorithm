#include <iostream>
#include <queue>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	int dur, x;
	int count = 0;
	bool check[100001] = { false , };
	bool flag = false;

	queue<int> q;

	q.push(n);
	check[n] = true;

	if (n == k)
		cout << 0;

	else
	{
		while (!q.empty())
		{
			dur = q.size();

			for (int i = 0; i < dur; i++)
			{
				x = q.front();
				if (x == k)
				{
					flag = true;
				}

				if (x + 1 <= 100000 && check[x + 1] == false)
				{
					q.push(x + 1);
					check[x + 1] = true;
				}

				if (x - 1 >= 0 && check[x - 1] == false)
				{
					q.push(x - 1);
					check[x - 1] = true;
				}
				if (2 * x <= 100000 && check[2 * x] == false)
				{
					q.push(2 * x);
					check[2 * x] = true;
				}

				q.pop();
			}

			if (flag == true)
				break;

			count++;
		}
		cout << count;
	}

	return 0;
}

