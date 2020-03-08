#include <iostream>
#include <queue>

using namespace std;
int F, S, G, U, D;
bool check[1000010] = { false, };
bool flag = false;
int cnt = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> F >> S>>G>>U>>D;
	queue<int> q;


	q.push(S);
	check[S] = true;
	while (!q.empty())
	{
		int ptr_size = q.size();
		for (int i = 0; i < ptr_size; i++)
		{
			int ptr = q.front();
			if (ptr + U <= F && !check[ptr + U])
			{
				check[ptr + U] = true;
				q.push(ptr + U);
			}
			if (ptr -D >= 1 && !check[ptr - D])
			{
				check[ptr - D] = true;
				q.push(ptr - D);
			}
			if (ptr == G)
			{
				bool flag = true;
				cout << cnt;
				return 0;
			}
			q.pop();
		}
		cnt++;
	}
	if (q.empty() && !flag)
	{
		cout << "use the stairs";
	}
	return 0;
}