#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long A, B, C; //a는 고정비용 b는 개수당 비용 c는 판매가격
	cin >> A >> B >> C;
	//c-(a+t*b)>0
	int cnt = 0;
	int margin = C-B;
	if (margin <= 0)
		cout << -1;
	else
	{
		cnt = A / margin + 1;
		cout << cnt;
	}
	return 0;
}