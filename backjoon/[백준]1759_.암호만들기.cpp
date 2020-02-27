#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<char>v;
queue<char>q;

int L, C;
char alpa[15];
int m_cnt = 0, j_cnt = 0;
bool alphabet[26] = { false, };
bool visited[26] = { false, };


void dfs(int k)
{
	if (k >= 2)
	{
		if (v[k - 1] < v[k - 2])
			return;
	}

	if (L == k)
	{
		if (m_cnt < 1 || j_cnt < 2)
			return;

		for (int i = 0; i < L; i++)
		{
			cout << v[i];
		}
		cout << "\n";
		return;
	}

	else
	{
	for (int i = 0; i < C; i++)
	{
		if (!visited[i])
		{
			v.push_back(alpa[i]);
			visited[i] = true;
			if (alpa[i] == 'a' || alpa[i] == 'e' || alpa[i] == 'i' || alpa[i] == 'o' || alpa[i] == 'u')
				m_cnt++;
			else
				j_cnt++;

			dfs(k + 1);

			if (alpa[i] == 'a' || alpa[i] == 'e' || alpa[i] == 'i' || alpa[i] == 'o' || alpa[i] == 'u')
				m_cnt--;
			else
				j_cnt--;
			visited[i] = false;
			v.pop_back();
		}
	}

	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;
	for (int t = 0; t < C; t++) // 알파벳 C개를 받음
	{
		cin >> alpa[t];
		//alphabet[alpa - 'a'] = true; // 존재하는 알파벳은 true
	}
	sort(alpa, alpa + C);
	dfs(0);

	return 0;
}