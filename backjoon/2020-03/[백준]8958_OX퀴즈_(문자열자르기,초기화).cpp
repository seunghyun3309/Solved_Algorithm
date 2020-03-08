#include <iostream>
#include <cstring>
using namespace std;

char str[81];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		int score = 0;
		int cnt = 1;
		cin >> str;// string형
		int idx = 0;
		while (idx<strlen(str))
		{
			if (str[idx] == 'O')
			{
				score += cnt;
				cnt++;

			}
			else
			{
				cnt = 1;
			}
				idx++;
		}
		cout << score<<"\n";
	}
	

	return 0;

}
