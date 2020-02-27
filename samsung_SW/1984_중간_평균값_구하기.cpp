#include <iostream>
#include <cmath>

using namespace std;

int n;
int result;
const int NUM = 10;

int main()
{
	int testcase;
	cin >> testcase;
	
	for(int tc=1;tc<=testcase;tc++)
	{
		double sum = 0;
		double average = 0.0;
		int arr[10];
		for (int i = 0; i < NUM; i++)
			cin >> arr[i];

		int max = 0;
		int min = 10000;
		for (int i = 0; i < NUM; i++)
		{
			if (max < arr[i])
				max = arr[i];
		}
		for (int i = 0; i < NUM; i++)
		{
			if (min > arr[i])
				min = arr[i];
		}

		for (int i = 0; i < NUM; i++)
		{
			sum += arr[i];
		}
		sum = sum-min-max;
		int num = NUM - 2;
		average = sum / num;
		cout << "#" << tc << " "<< round(average) << endl;
	}

	return 0;
}