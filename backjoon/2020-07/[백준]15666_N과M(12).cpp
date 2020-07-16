#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, m;
bool check[10] = { false, };
int arr[10];

vector<int>ret;
set<string>s;

void func(int k)
{
	if (m == k)
	{
		for (int i = 1; i < k; i++)
		{
			if (ret[i-1] > ret[i])
				return;
		}
		//sort(ret.begin(), ret.end());
		string tmp="";
		for (int i = 0; i < k; i++)
		{
			tmp += ret[i]+'0';
		}
		if (s.find(tmp) != s.end())
			return;

		s.insert(tmp);
		
		for (int i = 0; i < k; i++)
		{
			cout << ret[i] << " ";
		}
		cout << "\n";
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!check[i])
			{
				//check[i] = true;
				ret.push_back(arr[i]);
				func(k + 1);
				ret.pop_back();
				//check[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0);

	return 0;
}