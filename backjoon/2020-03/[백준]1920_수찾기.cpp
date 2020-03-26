#include <iostream>
#include <algorithm>
using namespace std;

int A[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}
	sort(A + 1, A + n + 1);
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> num;
		bool search_num = false;
		int start = 1, end = n;

		while (end >= start)
		{
			int mid = (start + end) / 2;
			if (A[mid] == num)
			{
				search_num = true;
				break;
			}
			else
			{
				if (A[mid] < num)//찾고자하는 수가 중간값보다 크면 
					start = mid + 1;//작은 범위 제외
				else
					end = mid - 1;

			}
		}
		if (search_num)
		{
			cout << 1 << "\n";
		}
		else
			cout << 0 << "\n";
	}

	return 0;
}
