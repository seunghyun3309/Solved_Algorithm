
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
		int n;
		int near = 0;
		int distance;
		int minimum = 100001;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> distance;
			if (distance < 0)
			{
				distance *= -1;
			}
			if (minimum > distance)
			{
				near = 1;
				minimum = distance;
			}
			else if (minimum == distance)
			{
				near++;
			}
		}
		cout << "#" << test_case << " " <<minimum<<" "<<near;
		cout << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}