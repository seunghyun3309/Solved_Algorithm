#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int map[101][101];
int dist;
int dist_sum = 0;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

bool check[101] = { false, };
int result = 98765432;

int calc(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.second - p2.second) + abs(p1.first - p2.first);
}

void dfs(int cnt, int len)
{
	if (cnt == M)
	{
		dist_sum = 0;
		for (int i = 0; i < v2.size(); i++) // 집집마다 최소를 찾아야 함
		{
			dist = 98765432;
			for (int j = 0; j < v1.size(); j++) //치킨집마다 선택된 치킨집에서 
			{
				if (check[j]) //j번째 치킨집을 선택
				{
					dist = min(dist, calc(v1[j], v2[i]));
				}
			}
			dist_sum += dist;
		}
		// cout<<dist_sum<<endl;
		if (result > dist_sum) //dist_sum이 더 작으면 업데이트
			result = dist_sum;
		return;
	}

	else if (len == v1.size()) return; //치킨집을 모두 선택했으면

	check[len] = true; //len번째 치킨집을 선택
	dfs(cnt + 1, len + 1);

	check[len] = false;
	dfs(cnt , len + 1);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) v1.push_back({ i,j });
			if (map[i][j] == 1) v2.push_back({ i,j });

		}
	}

	dfs(0,0); //앞은 선택한 개수 뒤는 선택할 개수
	cout << result;
	return 0;
}