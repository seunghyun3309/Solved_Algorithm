#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int cdt;
struct Info {
	int name;
	int num;
	int order;
};
bool check[1010] = { false, };
int delete_idx=0;

vector<Info>v1;
bool comp(Info v1, Info v2)
{
	if (v1.num < v2.num) //second가 크면 무조건 앞으로 이동
	{
		return false;
	}
	
	else if (v1.num == v2.num)
	{
		return v1.order > v2.order;
	}
	else //second가 왼쪽이 더 크면
		return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> cdt;
		if (!check[cdt] && v1.size() < n) //새로 등록
		{
			check[cdt] = true;
			v1.push_back({ cdt, 1, i });

		}
		else if (check[cdt]) // 추천 추가
		{
			for (int j = 0; j < v1.size(); j++)
			{
				if (v1[j].name == cdt)
					v1[j].num++;
			}
		}
		else
		{
			sort(v1.begin(), v1.end(), comp);
			if (!v1.empty())
			{
				delete_idx = v1[v1.size() - 1].name;
				// cout << "delete: "<<delete_idx<<endl;

				v1.pop_back();
				check[delete_idx] = false;
			}
			// 다시 넣는과정
			v1.push_back({ cdt, 1, i });
			check[cdt] = true;
		}
		/*for (int k = 0; k < v1.size(); k++)
		{
			cout<<v1[k].name<<" ";
		}
		cout << endl;*/
	}

	
	for (int i = 0; i < 101; i++)
	{
		if (check[i])
			cout << i << " ";
	}

	return 0;
}