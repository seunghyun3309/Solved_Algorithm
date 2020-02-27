#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int count[101] = { 0, };
		int num = 0;
		int many;
		int n,score,result;
		cin >> n;

		for (int i = 0; i < 1000; i++)
		{
			cin >> score;
			count[score]++;
		}
		for (int i = 1; i <= 100; i++)
		{
			if (count[i] >= num)
			{
				num = count[i];
				result = i;
			}
		}

		cout << "#" << n << " " << result <<endl;

	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}