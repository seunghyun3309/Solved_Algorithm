#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

const int MAX = 100000;


int main()
{
	for (int tc = 1; tc <= 10; tc++)
	{
		int n;
		cin >> n;
		string parenthesis;
		cin >> parenthesis;
		stack<char> s1;
		stack<char> s2;
		stack<char> s3;
		stack<char> s4;
		
		bool flag = true;
		for (int i = 0; i < parenthesis.size(); i++)
		{
			if (parenthesis[i] == '[')
			{
				s1.push('[');
			}
			else if (parenthesis[i] == '{')
			{
				s2.push('{');
			}
			else if (parenthesis[i] == '(')
			{
				s3.push('(');
			}
			else if (parenthesis[i] == '<')
			{
				s4.push('<');
			}
			if (parenthesis[i] == ']')
			{
				if (s1.empty())
					flag = false;
				else
				{
					s1.pop();
				}
			}
			else if (parenthesis[i] == '}')
			{
				if (s2.empty())
					flag = false;
				else
				{
					s2.pop();
				}
			}
			else if (parenthesis[i] == ')')
			{
				if (s3.empty())
					flag = false;
				else
				{
					s3.pop();
				}
			}
			else if (parenthesis[i] == '>')
			{
				if (s4.empty())
					flag = false;
				else
				{
					s4.pop();
				}
	
			}
		}
		if (!s1.empty() || !s2.empty() || !s3.empty() || !s4.empty())
		{
			flag = false;
		}

			cout << "#" << tc << " " << flag << endl;
	}
	return 0;
}