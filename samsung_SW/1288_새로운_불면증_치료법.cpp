
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	int command, up, down;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		int kN = N;
		int sum = 0;
		int k = 1;

		bool result[10] = { false, };
	
		while (1)
		{
			while (kN != 0)
			{
				if (result[kN % 10] == false)
					result[kN % 10] = true;
				kN /= 10;
			}
			sum = 0;
			for (int i = 0; i < 10; i++)
			{
				sum += result[i];
			}

			if (sum == 10)
				break;
			else
			{
				k+=1;
				kN =k * N;
			}
		}

		cout << "#" << test_case << " " <<k*N;
		cout << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}