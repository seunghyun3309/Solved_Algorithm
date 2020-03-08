#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int num_arr[101];
int arr_size = 0;
int n, m, k;
int max_num;
int cnt = 0;

int getMax(int arr[])
{
	int val = -1;
	for (int i = 0; i < arr_size; i++)
	{
		if (val < arr[i])
			val = arr[i];
	}

	return val;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++)
	{
		arr_size = 0;
		cnt = 0;
		queue<int> q; // 번호를 담는 큐

		// tc별로 초기화 되어야 하는 값

		cin >> n; // 문서 수
		cin >> m; // 몇번째 문서를 알고싶은가?
		for (int i = 0; i < n; i++)
		{
			q.push(i); //번째를 담는다
			cin >> k; // n개의 중요도를 담는다
			num_arr[arr_size++] = k;
		}

		while (1)
		{
			max_num = getMax(num_arr);
			if (num_arr[q.front()] == max_num) //조건을 만족하는 경우
			{
				cnt++;
				if (q.front() == m)
				{
					cout << cnt << "\n";
					break;
				}
				num_arr[q.front()] = -1; //중요도는 1부터 9사이
				q.pop();
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
	}
}