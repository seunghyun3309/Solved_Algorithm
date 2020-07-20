#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
map<char, int> m1;
vector<pair<char, int>>v1;

bool comp(pair<char, int>p1, pair<char, int> p2)
{
	return p1.second > p2.second;
}

int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			m1[str[i] - 'a' + 'A']++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			m1[str[i]]++;
		}
	}
	for (auto it = m1.begin(); it != m1.end(); it++)
	{
		v1.push_back(*it);
	}
	sort(v1.begin(), v1.end(), comp);

	if (v1.size()>=2&&v1[0].second == v1[1].second)
		cout << "?";
	else
		cout << v1[0].first;
}