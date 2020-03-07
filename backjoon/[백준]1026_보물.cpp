#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr_A[1010];
int arr_B[1010];

bool comp(int a, int b)// 같으면 반드시 false를 반환
{
	if (a <= b)
		return false;
	else
		return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr_A[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr_B[i];
	}

	sort(arr_A, arr_A + n);
	sort(arr_B, arr_B + n, comp); //큰

	int getMax = 0;

	for (int i = 0; i < n; i++)
	{
			getMax += arr_A[i] * arr_B[i];
	}

	cout << getMax;
	return 0;
}