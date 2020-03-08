#include <iostream>
using namespace std;

float arr[1010] = { 0, };
float getMax = -1;
float getSum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > getMax)
			getMax = arr[i];
	}

	float score[100];
	for (int i = 0; i < n; i++)
	{
		score[i] = float(arr[i] / getMax) * 100;
		getSum += score[i];
	}
	getSum /= n;
	cout << getSum;

	return 0;

}
