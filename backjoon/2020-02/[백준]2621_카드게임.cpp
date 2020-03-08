#include <iostream>
#include <algorithm>

using namespace std;
char color[5];
int number[5];
int num_cnt[10] = { 0, };

bool num_flag = true;
bool color_flag = true;

int cnt4 = -1;
int cnt3 = -1;
int cnt2 = -1;
int cnt1 = -1;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> color[i] >> number[i];
	}

	sort(number, number + 5);

	for (int i = 0; i < 4; i++)
	{
		if (number[i] + 1 != number[i + 1])
			num_flag = false;
		if (color[i] != color[i + 1])
			color_flag = false;

	}
	for (int i = 0; i < 5; i++)
	{
		num_cnt[number[i]]++;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (num_cnt[i] == 4)
		{
			cnt4 = i;
		}
		else if (num_cnt[i] == 3)
			cnt3 = i;

		else if (num_cnt[i] == 2)
		{
			if (cnt2 == -1)
				cnt2 = i;
			else
				cnt1 = i;
		}
	}
	//1번
	if (num_flag && color_flag)
	{
		cout << number[4] + 900;
	}

	else if (cnt4 > 0)
	{
		cout << cnt4 + 800;
	}

	else if (cnt3 >= 0 && cnt2 >= 0)
	{
		cout << cnt3 * 10 + cnt2 + 700;
	}

	else if (color_flag)
	{
		cout << number[4] + 600;
	}
	//5번
	else if (num_flag)
	{
		cout << number[4] + 500;
	}
	else if (cnt3 > 0)
	{
		cout << cnt3 + 400;
	}
	else if (cnt2 > 0 && cnt1 > 0)
	{
		cout << cnt1 * 10 + cnt2 + 300;
	}
	else if (cnt2 > 0)
	{
		cout << cnt2 + 200;
	}
	else
	{
		cout << number[4] + 100;
	}

	return 0;
}