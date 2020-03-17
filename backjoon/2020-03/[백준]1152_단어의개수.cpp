#include <iostream>
#include <string>
using namespace std;

string str;
int main()
{
	int cnt = 0;
	getline(cin, str);
	bool flag = false;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			flag = false;
		}
		else if(!flag)
		{
			flag = true;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}