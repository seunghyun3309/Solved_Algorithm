#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n;
int sum = 0;
double average;
int arr[500001] = { 0, };
int count_num[12001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (arr[i] < 0)
		{
			count_num[10000 + arr[i]]++;
		}
		else
			count_num[arr[i]]++;
	}
	average = (double)sum / n;
	//cout << average << endl;
		cout << floor(average + 0.5) << "\n";


	cout << arr[(n - 1) / 2] << "\n"; //n은 홀수

	int getMax = arr[n - 1];
	int getMin = arr[0];
	int max = -1;
	int max_num = -4001;
	vector<int>result;

	for (int i = getMin; i <= getMax; i++)
	{
		if (i >= 0)
		{
			if (count_num[i] > max)
			{
				result.clear();
				max = count_num[i];
				result.push_back(i);
			}
			else if (count_num[i] == max)
			{
				result.push_back(i);
			}
		}
		else
		{
			if (count_num[10000 + i] > max)
			{
				result.clear();
				max = count_num[10000 + i];
				result.push_back(i);
			}
			else if (count_num[10000 + i] == max)
			{
				result.push_back(i);
			}
		}
	}
	if (result.size() > 1)
	{
		cout << result[1] << "\n";
	}
	else
		cout << result[0] << "\n";

	cout << getMax - getMin << "\n";

	return 0;
}