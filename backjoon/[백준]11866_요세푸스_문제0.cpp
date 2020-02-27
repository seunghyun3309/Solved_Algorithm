#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
int n, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	cout << "<";
	while (q.size() > 0)
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop(); //맨앞을 맨뒤로 옮기는 과정을 
		}
		if (q.size() > 1)
			cout << q.front() << ", ";
		else
			cout << q.front() << ">";
		q.pop();
	}

	return 0;
}