#include <iostream>
using namespace std;
int main()
{
	int arr[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}
	int getSum = 0;
	if (arr[0] > arr[1])
	{
		if (arr[0] < arr[2])//2가 제일 큰 경우
			getSum += (arr[0]>arr[1]?arr[0]:arr[1]);
		else//0이 제일 큰 경우
			getSum += (arr[2] > arr[1] ? arr[2] : arr[1]);
	}
	else//0보다 1이 큼
	{
		if (arr[1] < arr[2]) //2가  제일 큰 경우
			getSum += (arr[0] > arr[1] ? arr[0] : arr[1]);
		else// 1이 제일 큰 경우
			getSum += (arr[0] > arr[2] ? arr[0] : arr[2]);
	}

	cout << getSum;
	
	return 0;

}
