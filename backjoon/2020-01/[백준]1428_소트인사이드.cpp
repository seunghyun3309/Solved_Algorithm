#include <iostream>
#include <algorithm>


using namespace std;

int n;
int arr[20] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int size = 0;
	int temp;
	while (n > 0)
	{
		arr[size++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	}
	for (int i = 0; i < size; i++)
		cout << arr[i];
	return 0;
}