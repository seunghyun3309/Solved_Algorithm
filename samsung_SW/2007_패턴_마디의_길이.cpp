#include <iostream>

using namespace std;

char arr[30];

int main()
{
	
	int testcase;
	cin >> testcase;


	for (int tc = 1; tc <= testcase; tc++)
	{
		int answer = 0;
		cin >> arr;
		for (int i = 10; i >= 1; i--) //마디 수
		{
			bool flag = true;
			
			for (int num = 0; num < i; num++) //0부터 i까지
			{
				while (num + i < 30)
				{
					if (arr[num] != arr[num + i]) //반복 수만큼 이동한 글자와 다르면
						flag = false;
					num += i;
				}
			}
			
			// flag=true 이면 answer=i;
			if (flag == true)
				answer = i;
		}

		cout << "#" << tc << " "<<answer<<endl;
		//결과
	}


	return 0;
}