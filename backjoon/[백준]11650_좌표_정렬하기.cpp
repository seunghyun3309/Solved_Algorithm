#include <iostream>
#include <algorithm>


using namespace std;

int n;

struct pos {
	int xpos;
	int ypos;
};
pos arr[100010];

bool comp(pos p1, pos p2)
{
	if (p1.xpos < p2.xpos)
		return true;
	else if (p1.xpos == p2.xpos)
	{
		return p1.ypos < p2.ypos;
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
		cout << arr[i].xpos <<" "<< arr[i].ypos<<"\n";
	}
	return 0;
}