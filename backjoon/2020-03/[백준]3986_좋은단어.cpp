#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 10000000;
string st;
stack<char> s;
int cnt = 0;
int main()
{
	int n;
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		while (!s.empty())
		{
			s.pop();
		}
		bool flag = true;
		cin >> st;
		for (int i = 0; i < st.length(); i++)
		{
			if (st[i] == 'A')
			{
				if (!s.empty()&&s.top() == 'A')
					s.pop();
				else
					s.push('A');
			}
			
			if (st[i] == 'B')
			{
				if (!s.empty()&&s.top() == 'B')
					s.pop();
				else
					s.push('B');
			}
		}
		if (!s.empty())
			flag = false;
		if (flag)
			cnt++;
	}
	
	cout << cnt;
	return 0;
}