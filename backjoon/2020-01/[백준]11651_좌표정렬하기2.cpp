#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int MAX = 100010;

struct ST {
	int xpos;
	int ypos;
};

ST arr[MAX];

bool comp(ST p1, ST p2)
{
	if (p1.ypos < p2.ypos)
	{
		return true;
	}
	else if (p1.ypos == p2.ypos)
	{
		return p1.xpos < p2.xpos;

	}
	else
		return false;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].xpos >> arr[i].ypos;
	}
	sort(arr, arr + n, comp);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].xpos << " " << arr[i].ypos << "\n";
	}

	return 0;
}