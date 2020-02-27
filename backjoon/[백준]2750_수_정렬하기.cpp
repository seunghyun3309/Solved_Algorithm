#include <iostream>

using namespace std;

int n;
int min_n, min_j;
int arr[1010];
int temp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		min_n = arr[i];
		min_j = i;
		for (int j = i; j < n; j++)
		{
			if (min_n > arr[j]) //최솟값 찾아서
			{
				min_n = arr[j];
				min_j = j;
			}
		}
		temp = arr[i];
		arr[i] = min_n;
		arr[min_j] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}