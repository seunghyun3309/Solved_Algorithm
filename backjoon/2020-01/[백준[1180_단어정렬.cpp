#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
const int MAX = 20010;

string arr[MAX];

bool comp(string p1, string p2)
{
	if (p1.size() < p2.size())
		return true;
	else if (p1.size() == p2.size())
	{
		if (p1.compare(p2) < 0)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, comp);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i - 1])
			continue;
		else
			cout << arr[i] << "\n";
	}
	return 0;
}