#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char arr[5][5];
int cnt = 0; //조건을 만족하는 갯수
bool check[5][5] = { false, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct Point {
	int xpos;
	int ypos;
};
vector<Point>v;

void dfs(int x_cnt, int y_cnt, int total)
{
	if (total==7)
	{
		//for (int i = 1; i < v.size(); i++)
		//{
		//	if (v[i - 1].xpos > v[i].xpos)
		//		return;
		//	else if (v[i - 1].xpos == v[i].xpos && v[i - 1].ypos > v[i].ypos)
		//		return;
		//}
		int som = 0;
		for (int i = 0; i < v.size(); i++)
		{
			//cout << v[i].xpos << " " << v[i].ypos << endl;
			if (arr[v[i].xpos][v[i].ypos] == 'S')
				som++;
		}
		if (som >= 4)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (check[i][j])
						cout << "0";
					else
						cout << "X";
				}
				cout << endl;
			}
			cnt++;
		}

		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int x_next = x_cnt + dx[i];
		int y_next = y_cnt + dy[i];
		if (!check[x_next][y_next] && x_next >= 0 && x_next < 5 && y_next >= 0 && y_next < 5)
		{
			check[x_next][y_next] = true;
			v.push_back({ x_next,y_next });
				dfs(x_next, y_next, total+1);
			v.pop_back();
			check[x_next][y_next] = false;
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
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << arr[i][j]<<" ";
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			check[i][j] = true;
			v.push_back({ i,j });
			if (arr[i][j] == 'S')
				dfs(i, j, 1);
			else
				dfs(i, j, 1);
			v.pop_back();
			check[i][j] = false;
		}
	}
	cout << cnt;
	return 0;
}