#include <iostream>
#include <cstring>
using namespace std;

int num[15];
char arr[16] = { ' ', };
int sum = 0;
int cnt = 0;
int n;

bool calculate(char ar[])
{

	for (int i = 0; i < 15; i++) //num 초기화
	{
		num[i] = i + 1; //{1,2,3,4,5,6...}  //num[0]=1, num[1]=2...
	}

	for (int k = n - 1; k >= 1; k--)
	{
		if (ar[k] == '.') //ar[14]부터 ar[1]까지
		{
			if (k >= 9) //num[k] 2자릿수인 경우
			{
				num[k - 1] = num[k - 1] * 100 + num[k];
			}
			else
			{
				num[k - 1] = num[k - 1] * 10 + num[k];
			}
		}
	}

	sum = num[0];

	for (int i = 1; i <= n - 1; i++)
	{
		if (ar[i] != '.')
		{
			switch (ar[i])
			{
			case '+':
			{
				sum += num[i];
				break;
			}
			case '-':
			{
				sum -= num[i];
				break;
			}
			}
		}

	}

	if (sum == 0)
		return true;

	else
		return false;

}


void f(char a, int b)
{
	arr[b] = a;
	if (b > n - 1)
	{
		return;
	}
	else if (b == n - 1)
	{
		if (calculate(arr))
		{
			cnt++;
			if (cnt <= 20)
			{
				for (int i = 1; i < n; i++)
					cout << i << " " << arr[i] << " ";
				cout << b + 1 << endl;
			}
		}
		return;
	}

	else
	{
		f('+', b + 1);
		f('-', b + 1);
		f('.', b + 1);
	}
}

int main()
{
	cin >> n;

	f(' ', 0);

	cout << cnt;
	return 0;
}
