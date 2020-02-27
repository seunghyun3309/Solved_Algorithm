
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int num[5] = { 2,3,5,7,11 };
	int result[5];
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int result[5] = { 0, };
		for (int i = 0; i < 5; i++)
		{
			while (n % num[i] == 0)
			{
				n /= num[i];
				result[i]++;
			}
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < 5; i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}