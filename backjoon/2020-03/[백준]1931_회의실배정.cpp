#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct Time {
	int start;
	int end;
};

Time arr[100010];

bool comp(Time t1, Time t2) //end부터 정렬
{
	if (t1.end < t2.end)
		return true;
	else if (t1.end == t2.end)
	{
		if (t1.start < t2.start)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].start >> arr[i].end;
	}

	sort(arr, arr + n, comp);

	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i].start<<" " << arr[i].end<<endl;
	//}

	int getMax = 0;
	int end_time = -1;
	for (int i = 0; i <n; i++)
	{
		if (arr[i].start >= end_time)
		{
			end_time = arr[i].end;
			getMax++;
		}
	}

	cout << getMax;
	return 0;
}