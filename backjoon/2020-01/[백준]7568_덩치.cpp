#include <iostream>

using namespace std;

int n;

struct big {
	int tall;
	int weight;
};

big arr[60] = { 0, };
int rank_arr[60];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].tall >> arr[i].weight;
	}
	for (int i = 0; i < n; i++)
	{
		rank_arr[i]=1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i].tall < arr[j].tall && arr[i].weight < arr[j].weight)
			{
				rank_arr[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << rank_arr[i]<<" ";
	}

	return 0;
}