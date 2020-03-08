#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, h;

const int MAX = 108;

int Graph[MAX][MAX][MAX];
bool check[MAX][MAX][MAX] = { false, };

int day = 0;
bool all_tomato = false;
bool not_tomato = false;

struct tomato {
	int xpos;
	int ypos;
	int zpos;
};

tomato make_node(int x, int y, int z) {
	tomato temp;

	temp.xpos = x;
	temp.ypos = y;
	temp.zpos = z;

	return temp;
};

queue<tomato> t;

int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0, 1, 0, -1,0,0 };
int dz[6] = { 0,0,0,0,1,-1, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> h; //가로칸 세로칸 높이
	for (int k = 0; k < h; k++) // 높이
	{
		for (int i = 0; i < n; i++) //n개의 줄 세로
		{
			for (int j = 0; j < m; j++) // 가로
			{
				cin >> Graph[i][j][k];
				if (!all_tomato && Graph[i][j][k] == 0)
				{
					all_tomato = true;
				}
				else if (Graph[i][j][k] == 1)
				{
					check[i][j][k] == true;
					t.push(make_node(i, j, k));
				}
			}
		}
	}

	if (all_tomato)
	{
		while (!t.empty())
		{
			int val = t.size();
			for (int d = 0; d < val; d++)
			{
				for (int p = 0; p < 6; p++)
				{
					int nx = t.front().xpos + dx[p];
					int ny = t.front().ypos + dy[p];
					int nz = t.front().zpos + dz[p];

					if (!check[nx][ny][nz] && Graph[nx][ny][nz] == 0 && nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h)
					{
						Graph[nx][ny][nz] = 1;
						check[nx][ny][nz] = true;
						t.push(make_node(nx, ny, nz));
					}
				}
				t.pop();
			}
			day++;
		}
	}

	for (int k = 0; k < h; k++) // 높이
	{
		for (int i = 0; i < n; i++) //n개의 줄 세로
		{
			for (int j = 0; j < m; j++) // 가로
			{
				if (Graph[i][j][k] == 0) //익지 않은 토마토가 있는 경우
				{
					not_tomato = true;
					break;
				}
			}
		}
	}

	if (!all_tomato)
		cout << 0;
	else if (not_tomato)
		cout << -1;
	else
		cout << day - 1;
	return 0;
}