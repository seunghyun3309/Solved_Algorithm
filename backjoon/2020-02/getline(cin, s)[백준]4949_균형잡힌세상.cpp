#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool flag = true;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	stack<char> st;

	while (1)
	{
		while (!st.empty())
		{
			st.pop();
		}
		getline(cin, s);
		flag = true;

		if (s.length() == 1 && s[0] == '.')
			break;

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '(')
			{
				st.push(s[j]);
			}
			else if (s[j] == '[')
			{
				st.push(s[j]);
			}
			else if (s[j] == ')')
			{
				if (!st.empty()&&st.top() == '(' )
				{
					st.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}
			else if (s[j] == ']')
			{
				if (!st.empty()&&st.top() == '[')
				{
					st.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (st.empty() && flag == true)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}

	return 0;
}