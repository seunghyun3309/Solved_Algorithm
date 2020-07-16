#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

string str1;
string str2;
int a, b, c = 0;
int k;
int str1_idx;
int str2_idx;
stack<int>result;

bool check()
{
	if (str1_idx < 0 && str2_idx < 0 && c == 0)
		return false;
	else
		return true;
}

int main()
{
	cin >> str1 >> str2;

	str1_idx = str1.length() - 1;
	str2_idx = str2.length() - 1;

	//cout << str1_idx << str2_idx << endl;
	// char 문자->숫자 +'0'
	// string 자체를 stoi

	//str1 11글자
	//str2 7글자로 가정
	while (check())
	{
		if (str1_idx < 0)
		{
			a = 0;
		}
		else
		{
			a = str1[str1_idx--] - '0';
		}
			
		if (str2_idx < 0)
		{
			b = 0;
		}
		else
		{
			b = str2[str2_idx--] - '0';
		}
		//cout << "a,b : " << a << " " << b << endl;
		k = a + b + c;
		c = k / 10;
		result.push(k%10);
	}
	while (!result.empty())
	{
		cout << result.top();
		result.pop();
	}
	return 0;
}