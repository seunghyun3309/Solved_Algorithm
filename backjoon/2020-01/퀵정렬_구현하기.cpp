#include <iostream>

using namespace std;

int n;
int min_n, min_j;
int arr[10000010];
int temp;

void quicksort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int pivot = left;
	int j_num = pivot;

	for (int i = pivot; i <= right; i++)
	{
		if (arr[i] < arr[pivot])
		{
			j_num++;
			temp = arr[j_num];
			arr[j_num] = arr[i];
			arr[i] = temp;
		}
	}

	temp = arr[j_num];
	arr[j_num] = arr[pivot];
	arr[pivot] = temp;
	pivot = j_num;

	quicksort(arr, left, pivot - 1);
	quicksort(arr, pivot + 1, right);
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

	quicksort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}