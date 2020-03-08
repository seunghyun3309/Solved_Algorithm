#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
const int MAX = 100010;

struct POS {
	int age;
	string name;
	int order;
};

POS arr[MAX];

bool comp(POS p1, POS p2)
{
	if (p1.age < p2.age)
		return true;
	else if (p1.age == p2.age)
		return p1.order < p2.order;
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
		cin >> arr[i].age >> arr[i].name;
		arr[i].order = i;
	}
	sort(arr, arr + n, comp);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].age << " " << arr[i].name << "\n";
	}

	return 0;
}