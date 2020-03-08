#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
struct test {
	int t1_score;
	int t2_score;
};
test arr[1000010];


bool comp(test s1, test s2) //true가 되면 s2는 선발 될수 없다.
{
	if (s1.t1_score < s2.t1_score)
		return true;
	else if (s1.t1_score == s2.t1_score)
		return s1.t2_score < s2.t2_score;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		bool recruit[1000010] = { false, };
		int cnt = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].t1_score >> arr[i].t2_score;
		}

		sort(arr, arr + n, comp);
		
		int t2_rank = arr[0].t2_score;
		for (int i = 1; i <n; i++)
		{
			if (arr[i].t2_score < t2_rank) //arr[i].t2가 더 작으면 업데이트 그 이외에는 탈락
				t2_rank = arr[i].t2_score;
			else
				cnt++;
		}
	
		cout << n-cnt<<"\n";
	}

	return 0;
}