
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
		cin >> n; //command 갯수

		int speed = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> command;
			if (command == 1)
			{
				cin >> up;
				speed += up;
			}
			else if (command == 2)
			{
				cin >> down;
				if (speed >= down)
				{
					speed -= down;
				}
				else
				{
					speed = 0;
				}
			}
			sum += speed;
		}
		cout << "#" << test_case << " " << sum;
		cout << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}