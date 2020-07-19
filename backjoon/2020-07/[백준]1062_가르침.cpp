#include <iostream>
#include <string>
#include <cstring>
#include<vector>
using namespace std;

int n, k;
int idx = 0;
int cnt, result = 0;
bool alpha[30] = { false, };
string str;
vector<string> st_arr;
bool flag = true;


void func(int start, int ap)
{
	if (ap == k-5)
	{
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			flag = true;
			for (int j = 0; j < st_arr[i].size(); j++)
			{
				if (!alpha[st_arr[i][j] - 'a'])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				cnt++;
		}
		if (cnt >= result)
			result = cnt;
		return;
	}
	else
	{
		for (int i = start; i < 26; i++)
		{
			if (!alpha[i])
			{
				alpha[i] = true;
				func(i, ap + 1);
				alpha[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		st_arr.push_back(str);
	}
	alpha[0] = true; //a
	alpha[2] = true; //c
	alpha[8] = true; //i
	alpha[13] = true; //n
	alpha[19] = true; //t
	func(0,0);
	cout << result;
	return 0;
}