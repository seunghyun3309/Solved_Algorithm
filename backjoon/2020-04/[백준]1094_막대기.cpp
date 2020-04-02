#include<iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int>v;
	int n;
	cin >> n;
	int start_len = 64;
	int cnt = 0;
	int len = start_len;
	int sum = 0;
	v.push_back(start_len);
	if (n == 64)
	{
		cout << 1;
		return 0;
	}
	
	while (1)
	{
		len = v[v.size() - 1];
		while (start_len - len < n)
		{
			v.pop_back();
			len /= 2;
			v.push_back(len);
			v.push_back(len);
		}
		start_len -= len;

		v.pop_back();

		int sum = 0;

		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		if (sum == n)
			break;
	}
	cout << v.size();
}