
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int result;
		int P, Q, R, S, W;
		cin >> P >> Q >> R >> S >> W;

		int A_WATER=0, B_WATER=0;

		A_WATER = W * P;
		B_WATER = Q;

		if(W>=R)
			B_WATER += S * (W - R);

		if (A_WATER > B_WATER)
			result = B_WATER;
		else
			result = A_WATER;
		
		cout << "#" << test_case << " "<<result;
		cout << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}