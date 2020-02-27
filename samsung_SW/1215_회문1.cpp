#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int main()
{

	for (int tc = 1; tc <= 10; tc++)
	{
		int count = 0;

		int n;
		cin >> n;

		char arr[8][8];

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> arr[i][j];
			}
		}
		stack<char> s;
		queue<char> q;
		for (int i = 0; i < 8; i++)
		{
			
			for (int j = 0; j <= 8 - n; j++)
			{
				bool flag = true;
				for (int k = 0; k < n; k++)
				{
					s.push(arr[i][j+k]);
					q.push(arr[i][j+k]);
				}
				while (!s.empty())
				{
					if (s.top() != q.front())
					{
						flag = false;
					}
					s.pop();
					q.pop();
				}
				if (flag == true)
					count++;
			}
		}
		for (int i = 0; i < 8; i++)
		{

			for (int j = 0; j <= 8 - n; j++)
			{
				bool flag = true;
				for (int k = 0; k < n; k++)
				{
					s.push(arr[j+k][i]);
					q.push(arr[j+k][i]);
				}
				while (!s.empty())
				{
					if (s.top() != q.front())
					{
						flag = false;
					}
					s.pop();
					q.pop();
				}
				if (flag == true)
					count++;
			}
		}
		cout << "#" << tc << " " << count<<endl;
	}

	return 0;
}