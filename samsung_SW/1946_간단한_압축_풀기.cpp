
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	char a[10]; int k[10];
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> k[i];
		}

		cout << "#" << test_case << endl;
        
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k[i]; j++)
			{
				cout << a[i];
				cnt++;
                if (cnt == 10)
				{
				cout << endl;
				cnt = 0;
				}
			}
		}
        cout<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}