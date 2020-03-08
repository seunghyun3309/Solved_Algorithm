#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;

vector<string> isEqual(vector<string>& not_hear, vector<string>& not_look)
{
	vector<string> not_hear_look;
	sort(not_hear.begin(), not_hear.end());
	sort(not_look.begin(), not_look.end());
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (not_hear[i] == not_look[j])
		{
			not_hear_look.push_back(not_hear[i]);
			i++;
			j++;
		}
		else if (not_hear[i] > not_look[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}
			
	
	return not_hear_look;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<string> not_hear(n);
	vector<string> not_look(m);
	for (int i = 0; i < n; i++)
	{
		cin >> not_hear[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> not_look[i];
	}

	vector<string>result=isEqual(not_hear, not_look);
	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	return 0;
}