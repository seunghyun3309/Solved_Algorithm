#include <iostream>

using namespace std;

const int MAX_SIZE = 1000010;
int n;
int arr[MAX_SIZE];
int sorted[MAX_SIZE] = { 0, };

void merge(int arr[], int left, int mid, int right)
{
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid)
	{
		for (int m = j; m <= right; m++)
			sorted[k++] = arr[m];
	}
	else
	{
		for (int m = i; m <= mid; m++)
		{
			sorted[k++] = arr[m];
		}
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = sorted[i];
	}
}
void mergesort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	mergesort(arr, left, mid);
	mergesort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	mergesort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}