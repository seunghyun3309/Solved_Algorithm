#include <iostream>
using namespace std;

int N, M;
int op, a, b;
int parent[1000010];

int findU(int x) //부모의 노드를 가져오는 함수
{
	if (x == parent[x]) //부모와 같아야 루트노드
		return parent[x];
	else // 루트노드가 나와야 끝나
	{
		int y = findU(parent[x]); // 부모의 번호를 새로 가져와
		parent[x] = y;// x의 부모의 번호 변경
		return y;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M; // N은 집합의 범위, M은 연산의 개수
	for (int i = 0; i <= N; i++) //0~N+1 까지 
	{
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)//연산 과정
	{
		cin >> op >> a >> b;
		if (op == 0)
		{
			a = findU(a); //a의 부모 찾고
			b = findU(b); //b의 부모 찾아서

			if (a > b) //기준에 따라서 부모노드 설정
				parent[a] = b;
			else if(a < b)
				parent[b] = a;
		}
		else if (op == 1)
		{
			a = findU(a);
			b = findU(b);
			if (a==b)
				cout << "YES" << "\n";
			else
			{
				cout << "NO" << "\n";
			}
		}
		//for (int i = 0; i <= N; i++)
		//{
		//	cout << parent[i] << " ";
		//}
		//cout<<endl;

	}
	return 0;
}