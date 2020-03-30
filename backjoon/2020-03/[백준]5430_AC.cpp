#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int>v;
deque<int>d;

int n; // 배열의 개수
char arr[400010];
char p[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++)
	{
		bool flag = true;
		bool isFront = true;
		while (!d.empty())
		{
			d.pop_back();
		}
		cin >> p; // 함수
		cin >> n;
		cin >> arr;
		int i = 1;
		while (arr[i] != ']')
		{
			int x = arr[i] - '0';
			i += 1;
			if (arr[i] == ',' || arr[i] == ']')
				d.push_back(x);
			else
			{
				int x2 = arr[i] - '0';
				x2 += 10 * x;
				i += 1;
				if (arr[i] == ',' || arr[i] == ']')
					d.push_back(x2);
				else
				{
					int x3 = arr[i] - '0';
					x3 += 10 * x2;
					i += 1;
						d.push_back(x3);
				}
			}
			if (arr[i] == ']')
				break;
			else
				i++;
		}
		int idx = 0;
		while (1)
		{
			if (p[idx] == 'R')
			{
				if (isFront)
					isFront = false;
				else
					isFront = true;
			}
			else if (p[idx] == 'D')
			{
				if (d.empty())
					flag = false;
				else if (isFront)
				{
					d.pop_front();
				}
				else
					d.pop_back();
			}
			else
			{
				break;
			}
			idx++;
		}
		if (!flag)
			cout << "error";
		else
		{
			if (isFront)
			{
				if (d.empty())
				{
					cout << "[]";
				}
				else
				{
					cout << "[";
					for (int i = 0; i < d.size() - 1; i++)
						cout << d[i] << ",";
					cout << d[d.size() - 1] << "]";
				}
				
			}
			else
			{
				if (d.empty())
				{
					cout << "[]";
				}
				else
				{
					cout << "[";
					for (int i = d.size() - 1; i > 0; i--)
						cout << d[i] << ",";
					cout << d[0] << "]";
				}
			}

		}
		
		cout << endl;
	}
	return 0;
}
