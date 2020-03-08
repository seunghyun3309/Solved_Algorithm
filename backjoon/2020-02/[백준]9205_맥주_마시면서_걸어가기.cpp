#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int n;
bool flag = false;
int xpos[1010];
int ypos[1010];
bool check[1010] = { false, };

void dfs(int x, int y)
{
	//cout << x << " " << y << "\n";
	if (x == xpos[n + 1] && y == ypos[n + 1])
	{
		flag = true;
		return;
	}
	else
	{
		for (int i = 0; i < n + 2; i++)
		{
			if (!check[i]&&(abs(x - xpos[i]) + abs(y - ypos[i])) <= 1000)
			{
				check[i] = true;
				dfs(xpos[i], ypos[i]);
				//check[i] = false;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		memset(check, false, sizeof(check));
		flag = false;

		cin >> n;

		for (int i = 0; i < n + 2; i++)
		{
			cin >> xpos[i] >> ypos[i];
		}

		check[0] = true;
		dfs(xpos[0], ypos[0]);

		if (flag)
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
	return 0;
}