#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char arr[5][5];
int cnt = 0; //조건을 만족하는 갯수
bool check[5][5] = { false, };
bool check2[5][5] = { false, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int result = 0;
int idx=1;
struct Point {
	int xpos;
	int ypos;
};
vector<int>v;
queue<Point>q;

void som4(vector<int>v)
{
	int som = 0;
	for (int i = 0; i < 7; i++)
	{
		//cout << v[i] << " ";
		if (arr[v[i] / 5][v[i] % 5] == 'S')
			som++;
	}
	//cout << endl;
	if (som >= 4)
		result++;
}

bool isconnected(vector<int> v)
{
	memset(check2, false, sizeof(check2));
	q.push({ v[0] / 5, v[0] % 5 });
	check2[v[0] / 5][v[0] % 5] = true;
	idx = 1;
	while (!q.empty())
	{
			int qx = q.front().xpos;
			int qy = q.front().ypos;
			for (int d = 0; d < 4; d++)
			{
				int nx = qx + dx[d];
				int ny = qy + dy[d];
				if (check[nx][ny]&&!check2[nx][ny]&&nx>=0&&nx<5&&ny>=0&&ny<5)
				{
					check2[nx][ny] = true;
					q.push({ nx,ny });
					idx++;
				}
			}
		q.pop();
	}
	if (idx >= 7)
		return true;
	else
		return false;
}

void R(int start, int cnt)
{
	if (cnt == 7)
	{
		/*for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;*/
		if (isconnected(v))
		{
			som4(v);
		}
		return;
	}
	for (int i = start; i < 25; i++)
	{
		if (!check[i / 5][i % 5])
		{
			check[i / 5][i % 5] = true;
			v.push_back(i);
			R(i, cnt + 1);
			v.pop_back();
			check[i / 5][i % 5] = false;
		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	R(0, 0);
	cout << result;

	return 0;
}