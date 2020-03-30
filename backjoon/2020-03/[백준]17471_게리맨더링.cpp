#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
int arr[20];
bool Graph[20][20] = { false, };
bool check[20] = { false, };
int result = -1;// 최종 정답
vector<int>v;
void dfs(int start, int cnt);
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int adj_num;
		cin >> adj_num;
		for (int j = 0; j < adj_num; j++)
		{
			int adj_v;
			cin >> adj_v;
			Graph[i][adj_v] = true;
		}
	} //여기까지는 맞아
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << Graph[i][j]<<" ";
	//	}
	//	cout << endl;
	//}

	for (int k = 1; k < n; k++)//n일때
	{
		dfs(0, k);
	}

	cout << result;
	return 0;
}

bool isConnected(int st, vector<int> f_arr)
{
	if (f_arr.empty())
		return false;

	queue<int>q;
	bool f_checked[20] = { false, };
	q.push(st);
	f_checked[st] = true;
	int q_cnt = 0;
	while (!q.empty())
	{
		int qf = q.front();
		for (int i = 0; i < f_arr.size(); i++)
		{
			if (!f_checked[f_arr[i]] && Graph[f_arr[i]][qf])
			{
				q.push(f_arr[i]);
				f_checked[f_arr[i]] = true;
			}
		}
		q_cnt++;
		q.pop();
	}

	if (q_cnt == f_arr.size())
		return true;
	else
		return false;
}

void dfs(int start, int cnt) //start는 선택한 개수 cnt=마을의 개수
{
	vector<int> v;
	vector<int>t_arr;//선택된 마을
	vector<int>f_arr;//선택되지 않은 마을
	if (start == cnt)
	{
		for (int i = 1; i <= n; i++)
		{
			if (check[i])
				t_arr.push_back(i);
			else
				f_arr.push_back(i);
		}
		if (isConnected(t_arr[0], t_arr) && isConnected(f_arr[0], f_arr))
		{
			int first = 0;
			int second = 0;
			for (int p = 0; p < t_arr.size(); p++)
			{
				first += arr[t_arr[p]];
			}

			for (int p = 0; p < f_arr.size(); p++)
			{
				second += arr[f_arr[p]];
			}

			if (result < 0)
			{
				result = abs(second - first);
			}
			else
			{
				if (result > abs(second - first))
				{
					result = abs(second - first);
				}
			}
		}
	}
	else//start개 만큼 선택
	{
		for (int i = start + 1; i <= n; i++)
		{
			if (!check[i])
			{
				v.push_back(i);
				check[i] = true;
				dfs(start + 1, cnt);
				check[i] = false;
				v.pop_back();
			}
		}
	}
}