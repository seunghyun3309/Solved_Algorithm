#include <iostream>
#include <stack>
#include <cstring>
#include <cctype> //isdigit
using namespace std;

bool flag = false;
int result = 0;
int temp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> number;
	stack<char>op;
	char str[55];
	cin >> str;

	char merge_digit[10];
	int merge_result;

	for (int i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]))
		{
			memset(merge_digit, 0, sizeof(merge_digit));
			int d = 0;
			do {
				merge_digit[d++] = str[i++];
			} while (isdigit(str[i]));

			merge_result = atof(merge_digit);
			number.push(merge_result);
			op.push(str[i]);
		
			if (!flag)// -되기전
			{
				result += number.top();
			}

			else
			{
				result -= number.top();
			}
			if (op.top() == '-')
				flag = true;

		}
	}
	
	cout << result<<"\n";
	return 0;
}