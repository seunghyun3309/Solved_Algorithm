#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;

bool isEqual(vector<string>& tele_num, int n)
{
	for (int i = 1; i < n; i++)
	{
		string& target = tele_num[i];
		string& compare = tele_num[i - 1];
		int len;
		if (target.length() < compare.length())
			len = target.length();
		else
			len = compare.length();
		//target과 compare 중 더 짧은 length를 사용
		int cnt = 0;
		for (int k = 0; k < len + 1; k++)
		{
			if (cnt == k) //둘중 하나가 끝나면 false를 리턴
			{
				if (compare[k] == '\0' && target[k] != '\0')
					return false;
				if (compare[k] != '\0' && target[k] == '\0')
					return false;
				else if (compare[k] == target[k])//k번째가 같으면 계속 진행 
					cnt++;

			}
			else if (cnt != k) //cnt가 늘어나지 않으면 break;
			{
				break;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++)
	{
		cin >> n;
		vector<string> tele_num(n);

		for (int i = 0; i < n; i++)
		{
			cin >> tele_num[i];

		}
		sort(tele_num.begin(), tele_num.end());

		bool flag;
		if (n == 1)
			flag = true;
		else
			flag = isEqual(tele_num, n);

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}