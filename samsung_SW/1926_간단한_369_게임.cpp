#include <iostream>

using namespace std;

int main()
{
	int n;
	int num;
	bool flag = false;

		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			bool flag = false;
			num=j;
			while (num > 9)
			{
					if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9)
					{
						flag = true;
						cout << "-";
					}
					num = num /10; //일의자리 당김
	
			}
			
			if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9) //한자리수인 경우
			{
				flag = true;
				cout << "-";
			}

			if (flag == false)
			{
				cout << j;
			}

			cout << " ";
		}

	return 0;
}