#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	stack<int> st;
	vector<char> v;

	int n;
	int st_num = 1;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int k = 0; k < n; k++)
	{
		int ptr = arr[k];
		if (st_num <= ptr)
		{
			for (int i = st_num; i <= ptr; i++)
			{
				st.push(i);
				v.push_back('+');
				st_num++;
			}
		}
		if (!st.empty() && arr[k] == st.top())
		{
			st.pop();
			v.push_back('-');
		}
	}

	if (!st.empty())
	{
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << "\n";
		}
	}

	return 0;
}