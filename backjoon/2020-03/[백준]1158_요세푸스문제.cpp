#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 5010;
bool checked[MAX] = { false, };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	int n, k;
	cin >> n >> k;
	int idx = 1;

	int c_num = 0;
	while (c_num < n)
	{
		int jmp = 0;
		while (1)
		{
			if (!checked[idx])
			{
				jmp++;
				if (jmp >= k)
					break;
			}
			if (idx < n)
				idx++;
			else
				idx = 1;
		}
		checked[idx] = true;
		c_num++;
		v.push_back(idx);
	}
	cout << "<";
	for (int i = 0; i < v.size()-1; i++)
	{
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << ">";
	return 0;
}
