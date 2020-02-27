#include <iostream>
using namespace std;

int n,k;
int idx_k;
int rank_num = 1;

struct olympic {
	int idx;
	int gold;
	int silver;
	int bronze;
};

olympic arr[10010];
int main()
{
	cin >> n>> k;

	for (int i = 1; i <= n; i++)
	{
		cin >>arr[i].idx >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
		if (arr[i].idx == k)
		{
			idx_k = i;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (arr[idx_k].gold < arr[i].gold)
		{
			rank_num++;
		}
		else if (arr[idx_k].gold == arr[i].gold)
		{
			if (arr[idx_k].silver < arr[i].silver)
			{
				rank_num++;
			}
			else if (arr[idx_k].silver == arr[i].silver)
			{
				if (arr[idx_k].bronze < arr[i].bronze)
				{
					rank_num++;
				}
			}
		}
	}
	
	cout << rank_num;
	return 0;
}