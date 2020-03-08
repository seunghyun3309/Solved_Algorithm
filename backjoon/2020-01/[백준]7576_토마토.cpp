#include <iostream>
#include <string>
#include <queue>
using namespace std;

int m, n;
int t, x, y;
int nx, ny;

int Graph[1001][1001] = { 0, };
bool check[1001][1001] = { false, };
char map[101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };
int result[1001][1001] = { 0, };
bool all_tomato = false;
bool not_tomato = true;
int max_result = 0;
int day = 0;
int duration;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> x_cnt;
	queue<int> y_cnt;

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Graph[i][j];

			if (Graph[i][j] == 0)
			{
				all_tomato = true;
			}
			else if (Graph[i][j] == 1)
			{
				check[i][j] = true;
				x_cnt.push(i);
				y_cnt.push(j);
			}

		}
	}

	//for (int i = 0; i < n; i++)//m번 입력 받기
	//{
	//	cin >> map;
	//	for (int j = 0; j < m; j++)
	//	{
	//		Graph[i][j] = map[j] - '0';
	//	}
	//}

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout<<Graph[i][j]<<" " ;
		//	}
		//	cout << "\n";
		//}

	if (all_tomato == true)
	{
		day = 0; //익는 날짜
		while (!x_cnt.empty() && !y_cnt.empty())
		{
			duration = x_cnt.size();
			for (int que = 0; que < duration; que++)
			{
				x = x_cnt.front();
				y = y_cnt.front();

				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (Graph[nx][ny] == 0 && check[nx][ny] == false
						&& nx >= 0 && nx < n && ny >= 0 && ny < m)
					{
						Graph[nx][ny] = 1;
						check[nx][ny] = true;
						x_cnt.push(nx);
						y_cnt.push(ny);
					}

				}
				x_cnt.pop();
				y_cnt.pop();
			}
			day++;
		}


		//for (int i = 0; i < n; i++)
		//	{
		//		for (int j = 0; j < m; j++)
		//		{
		//			cout<<Graph[i][j]<<" " ;
		//		}
		//		cout << "\n";
		//	}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Graph[i][j] == 0) //익지 않은 토마토가 있는 경우
				{
					not_tomato = false;
					break;
				}
			}
		}
		if (not_tomato == false)
		{
			cout << -1;
		}
		else
			cout << day - 1;
	}


	else //모든 토마토가 익어있는 경우
	{
		cout << 0;
	}
	return 0;
}

